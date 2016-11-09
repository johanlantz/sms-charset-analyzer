#include "sms.h"
#include "sms_defines.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#ifdef __ANDROID__
#include <android/log.h>
#endif

#define THIS_FILE   "sms.c"

#define DO_TRACE    0
static void LOCAL_TRACE(const char* format, ...)
{
    if (DO_TRACE) {
        va_list argptr;
        va_start(argptr, format);
#ifdef __ANDROID__
        __android_log_vprint(3, "sms", format, argptr);
#else
        vfprintf(stderr, format, argptr);
#endif
        va_end(argptr);
    }
}

typedef struct code_table {
    char* name;
    uint16_t* table;
    int table_len;
    uint16_t* shift_table;
    int shift_table_len;
} code_table;

/*Swiss cheese array to be able to index the encoders directly from the bitmap.*/
static code_table code_tables[ENC_UCS2 + 1] = {\
    {"",0,0,0,0},
    {"GSM-7", &basic_char_set[0][0], GSM7_TABLE_SIZE, &basic_char_set_extension[0][0], BASIC_CHAR_SET_EXT_LEN},
    {"GSM-7-ES", &basic_char_set[0][0], GSM7_TABLE_SIZE, &spanish_shift_set[0][0],SPANISH_SHIFT_SET_LEN},
    {"",0,0,0,0},
    {"HP-ROMAN-8", &hp_roman8_char_set[0][0], HP_ROMAN_8_TABLE_SIZE, NULL, 0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"ASCII", &ascii_char_set[0][0], ASCII_TABLE_SIZE, NULL,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"LATIN1", &latin1_char_set[0][0], LATIN1_TABLE_SIZE, NULL,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"",0,0,0,0},
    {"UCS-2",0,0,0,0}
};


static uint16_t BE_BOM = 0xfeff;
static uint16_t LE_BOM = 0xfffe;

unsigned supported_encoders = 0; //ENC_GSM7 | ENC_GSM7ES | ENC_UCS2;
int default_encoder = 0;

void sms_set_supported_encoders(int encoders, int default_encoder_id)
{
    supported_encoders = encoders;
    default_encoder = default_encoder_id;
}

void sms_get_supported_encoder_mapping(const char* encoder_name, int* encoder_id)
{
    int i = 0;
    *encoder_id = -1;
    for (i = 0; i<= ENC_UCS2; i++) {
        if (strcmp(code_tables[i].name, encoder_name) == 0) {
            LOCAL_TRACE("Found array id=%d for encoder: %s", i, encoder_name);
            *encoder_id = i;
            return;
        }
    }
    LOCAL_TRACE("Error: Failed to get array mapping for encoder %s", encoder_name);
}

char* sms_get_subset_as_string(int subset)
{
    if (subset <= 0 || subset > ENC_UCS2) {
        return NULL;
    }
    return code_tables[subset].name;
}

/*Helper to find a 16 bit character in a coding table*/
uint16_t* table_strchr(uint16_t* table, int table_len, uint16_t* chr)
{
    uint16_t* table_walker = table + 1; //table_walker now points to the second column of the UTF-16 values
    uint16_t* table_end = table + table_len*2;

    do {
        if (*table_walker == *chr) {
            return table_walker;
        }
        table_walker = table_walker + 2; //move to the next unicode column
    } while (table_walker < table_end);
    return NULL;
}

void sms_get_info(void* msg_buf, int buf_len, int* no_of_messages, int* characters_left_in_current_fragment,
                     int* selected_encoder, int* selected_encoder_is_default)
{
    int i = 0;
    unsigned current_encoder;

    uint16_t* message = (uint16_t*)msg_buf;
    int msg_len = buf_len / 2;

    if (supported_encoders == 0) {
        LOCAL_TRACE("Warning: No encoders have been defined. Will default to UCS2 only mode.");
        supported_encoders = ENC_UCS2;
    }

    if (message[0] == BE_BOM) {
        LOCAL_TRACE("Big Endian BOM detected. Platform should use BE.");
        message++;
        msg_len--;
    } else if (message[0] == LE_BOM) {
        LOCAL_TRACE("Little Endian BOM detected. Platform should use LE.");
        message++;
        msg_len--;
    } else {
        LOCAL_TRACE("No BOM detected, platform default is used.");
    }

    LOCAL_TRACE("Will print message with %d bytes = %d characters", buf_len, msg_len);
    //1. Try our 7 bit GSM encoders i.e. all encoders below the first 8 bit one (HP-Roman-8)
    for (current_encoder = 1; current_encoder < ENC_HP_ROMAN8; current_encoder = current_encoder << 1) {
        int septets = 0;
        int available_payload_size_septets = SMS_PAYLOAD_SIZE_SEPTETS;
        int udh_length_septets = 0;

        if (!(current_encoder & supported_encoders)) {
            LOCAL_TRACE("encoder %d not active\n", current_encoder);
            continue;
        }
        //We support this type of GSM encoding, lets see if our message likes it
        for (i=0; i < msg_len; i++) {
            if (table_strchr(code_tables[current_encoder].table, code_tables[current_encoder].table_len, &message[i])) {
                LOCAL_TRACE("Found match for 0x%04x, using encoder %d in default/lock table -> one point\n", message[i],
                            current_encoder);
                septets++;
            } else if (code_tables[current_encoder].shift_table &&
                       table_strchr(code_tables[current_encoder].shift_table, code_tables[current_encoder].shift_table_len, &message[i])) {
                LOCAL_TRACE("Found match for 0x%04x, using encoder %d shift table -> two points\n", message[i], current_encoder);
                septets+=2;
                udh_length_septets = UDH_COST_SINGLE_SHIFT_TABLE_SEPTETS;
            } else {
                LOCAL_TRACE("No match for 0x%04x in encoder %d. Try with the next encoder.\n", message[i], current_encoder);
                break;
            }
        }

        if (i == msg_len) {
            LOCAL_TRACE("Encoder %s can encode this message, no further checks needed.\n", code_tables[current_encoder].name);
            *selected_encoder = current_encoder;

            if ((code_tables[current_encoder].table != &basic_char_set[0][0] && udh_length_septets > 0)) {
                udh_length_septets = UDH_BASE_COST_SEPTETS + UDH_COST_TWO_SHIFT_TABLES_SEPTETS;
                LOCAL_TRACE("Encoder will use locking+shift tables, udh_len = %d septets\n", udh_length_septets );
            } else if (code_tables[current_encoder].table != &basic_char_set[0][0] || udh_length_septets > 0) {
                udh_length_septets = UDH_BASE_COST_SEPTETS + UDH_COST_SINGLE_SHIFT_TABLE_SEPTETS;
                LOCAL_TRACE("Encoder will use one shift table, udh_len = %d septets\n", udh_length_septets );
            } else {
                udh_length_septets = 0;
                LOCAL_TRACE("Encoder does not use shift or locking tables, no udh septet cost.\n");
            }

            if ((septets + udh_length_septets) > SMS_PAYLOAD_SIZE_SEPTETS) {
                udh_length_septets = UDH_BASE_COST_SEPTETS + UDH_COST_CONCATENATED_MESSAGE_SEPTETS;
                LOCAL_TRACE("We must use sms concatenation, udh length set to:%d\n", udh_length_septets);
            }

            available_payload_size_septets = SMS_PAYLOAD_SIZE_SEPTETS - udh_length_septets;
            LOCAL_TRACE("Available payload size calculated as:%d for udh_length:%d and numberOfSeptets:%d\n",
                        available_payload_size_septets, udh_length_septets, septets);

            if (available_payload_size_septets == 1) {
                LOCAL_TRACE("Exactly one septet left, if we were encoding this septet would be filled with a CR.");
            }

            *no_of_messages = (septets + available_payload_size_septets - 1) / available_payload_size_septets;
            LOCAL_TRACE("This will produce %d sms messages\n", *no_of_messages);
            *characters_left_in_current_fragment = available_payload_size_septets - (septets % available_payload_size_septets);
            if (*characters_left_in_current_fragment == available_payload_size_septets) {
                LOCAL_TRACE("We have moved into the next fragment, this letter is the last in this message\n");
                *characters_left_in_current_fragment = 0;
            } else if (*characters_left_in_current_fragment < 0) {
                LOCAL_TRACE("Error: *characters_left_in_current_fragment < 0");
            }
            *selected_encoder = current_encoder;
            break;
        }
    }

    //2. We have tried all GSM encoders. Try 8 bit encoders if supported.
    if (i < msg_len) {
        LOCAL_TRACE("Msg not possible to encode using GSM enconding. Try with 8 bit encoders if available. Each char will need 1 byte.\n");
        for (; current_encoder < ENC_UCS2; current_encoder = current_encoder << 1) {
            int octets = 0;
            if (!(current_encoder & supported_encoders)) {
                LOCAL_TRACE("8 bit encoder %s not active\n", code_tables[current_encoder].name);
                continue;
            }
            //We support this encoder, lets see if our message likes it
            for (i=0; i < msg_len; i++) {
                if (table_strchr(code_tables[current_encoder].table, code_tables[current_encoder].table_len, &message[i])) {
                    LOCAL_TRACE("Found match for 0x%04x, using 8 bit encoder %s\n", message[i],
                                code_tables[current_encoder].name);
                    octets++;
                } else {
                    LOCAL_TRACE("No match for 0x%04x in 8 bit encoder %d. Try with the next encoder.\n", message[i], current_encoder);
                    break;
                }
            }

            if (i == msg_len) {
                int available_payload_size_octets = (octets <= SMS_PAYLOAD_SIZE_OCTETS) ? SMS_PAYLOAD_SIZE_OCTETS :
                                                    SMS_PAYLOAD_SIZE_OCTETS - UDH_COST_CONCATENATED_MESSAGE_OCTETS;
                LOCAL_TRACE("Encoder %s can encode this message, no further checks needed.\n", code_tables[current_encoder].name);
                *no_of_messages = (msg_len + available_payload_size_octets - 1) / available_payload_size_octets;
                *characters_left_in_current_fragment = available_payload_size_octets - (msg_len % available_payload_size_octets);
                if (*characters_left_in_current_fragment == available_payload_size_octets) {
                    LOCAL_TRACE("We have moved into the next fragment, this letter is the last in this message");
                    *characters_left_in_current_fragment = 0;
                } else if (*characters_left_in_current_fragment < 0) {
                    LOCAL_TRACE("Error: *characters_left_in_current_fragment < 0");
                }
                *selected_encoder = current_encoder;
                break;
            }
        }
    }

    //3. We have tried all 7 and 8 bit encoders without success, use UCS2
    if (i < msg_len) {
        int available_payload_size_double_octets = (msg_len <= SMS_PAYLOAD_SIZE_WORD) ? SMS_PAYLOAD_SIZE_WORD :
                SMS_PAYLOAD_SIZE_WORD - UDH_COST_CONCATENATED_MESSAGE_WORD;
        LOCAL_TRACE("Msg not possible to encode using neither GSM 7 bit enconding nor 8 bit encoders. UCS2 is needed. Each char will need 2 bytes.\n");
        *no_of_messages = (msg_len + available_payload_size_double_octets - 1) / available_payload_size_double_octets;
        *characters_left_in_current_fragment = available_payload_size_double_octets - (msg_len %
                                               available_payload_size_double_octets);
        if (*characters_left_in_current_fragment == available_payload_size_double_octets) {
            LOCAL_TRACE("We have moved into the next fragment, this letter is the last in this message");
            *characters_left_in_current_fragment = 0;
        } else if (*characters_left_in_current_fragment < 0) {
            LOCAL_TRACE("Error: *characters_left_in_current_fragment < 0");
        }
        *selected_encoder = ENC_UCS2;
    }

    if (*selected_encoder == default_encoder) {
        LOCAL_TRACE("Selected encoder is the last one provisioned.");
        *selected_encoder_is_default = 1;
    } else {
        LOCAL_TRACE("Selected encoder is not the last one provisioned.");
        *selected_encoder_is_default = 0;
    }
}

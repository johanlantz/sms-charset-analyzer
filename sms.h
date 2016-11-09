/*
 * sms.h
 * 
 * Drop in api for analyzing the optimal charset for sms encoding.
 * Supports identifying the most optimal encoding as well as calculating
 * the number of sms messages needed and the space left in the current 
 * fragment.
 *
 *  Created on: 02/04/2013
 *      Author: johan
 */

#ifndef SMS_H
#define SMS_H

typedef enum sms_encoders {
    /*Standard GSM7 encoding*/
    ENC_GSM7                             = 0x01,
    /*GSM7 encoding with Spanish support*/
    ENC_GSM7ES                           = 0x02,
    /*HP-ROMAN8 encoding*/
    ENC_HP_ROMAN8                        = 0x04,
    /*ASCII encoding*/
    ENC_ASCII                            = 0x08,
    /*Latin1 encoding*/
    ENC_LATIN1                           = 0x10,
    /*UCS2 encoding. This option must be last*/
    ENC_UCS2                             = 0x20
} sms_encoders;

/* 
 * Sets the supported encoders.
 * @param encoders              Bitmap of supported sms encoders from #sms_encoders
 * @param default_encoder_id    Encoder to use as default option
 */
void sms_set_supported_encoders(int encoders, int default_encoder_id);

/*
 * Get encoder id from string.
 * @param encoder_name          Name of the encoder e.g. GSM-7
 * @param encoder_id            Int pointer to be assigned with the encoder id (or -1 if not supported)
 */
void sms_get_supported_encoder_mapping(const char* encoder_name, int* encoder_id);

/*
 * Get string representation from encoder id
 * @param subset                The encoder id
 * @returns                     The string representation of the encoder such as GSM-7
 */
char* sms_get_subset_as_string(int subset);

/*
 * From a UTF-16 encoded byte buffer, calculate various sms parameters.
 * @param msg_buf                               Pointer to UTF-16 encoded buffer with a sms message to analyze
 * @param buf_len                               Length of buffer in bytes
 * @param no_of_messages                        Number of sms messages needed using the least expensive of the supported encoders
 * @param characters_left_in_current_fragment   Characters left in the last sms fragment
 * @param selected_encoder                      The most optimal encoding for this message (from the supported ones in the bitmap)
 * @param selected_encoder_is_default           True if the most optimal encoding is also the one set as default in #sms_set_supported_encoder
 */
void sms_get_info(void* msg_buf, int buf_len, int* no_of_messages, int* characters_left_in_current_fragment,
                     int* selected_encoder, int* selected_encoder_is_default);

#endif


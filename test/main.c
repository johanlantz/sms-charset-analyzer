//
//  main.c
//  Simple sms main function as example only. 
//  GTest unit tests are available in another folder.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "sms.h"

int main(int argc, const char * argv[]) {
    uint16_t msg_buf_utf_16_gsm7[5] = {0x0020, 0x0020, 0x0020, 0x0020, 0x0020};
    int no_of_messages = 0;
    int characters_left_in_current_fragment = 0;
    int selected_encoder = -1;
    int selected_encoder_is_default = 0;

    printf("Starting sms analyzer!\n");
    
    sms_set_supported_encoders(ENC_GSM7 | ENC_GSM7ES | ENC_HP_ROMAN8 | ENC_ASCII | ENC_LATIN1 | ENC_UCS2, ENC_UCS2);
    sms_get_info((void*)msg_buf_utf_16_gsm7, 5*sizeof(uint16_t), &no_of_messages, &characters_left_in_current_fragment,
                     &selected_encoder, &selected_encoder_is_default);

    assert((no_of_messages == 1) && (characters_left_in_current_fragment == 155) && (selected_encoder == ENC_GSM7));

    printf(" no_of_messages=%d\n characters_left_in_current_fragment=%d\n selected_encoder=%d (%s)\n", no_of_messages, characters_left_in_current_fragment, selected_encoder, sms_get_subset_as_string(selected_encoder));

    printf("Test passed ok. Press any key to exit.");
    getchar();
    return 0;
}

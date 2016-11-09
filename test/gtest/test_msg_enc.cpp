
#include <sms_defines.h>
#include "gtest/gtest.h"

static uint16_t* fill_16bitBuffer(uint16_t* buffer_p, int bufLen, uint16_t* table_p, int tableLen)
{
    int i = 0;
    int j = 0;
    uint16_t* tableWalker_p = table_p + 1;
    uint16_t* bufferWalker_p = buffer_p;

    for (i=0; i < bufLen; i++, bufferWalker_p++, tableWalker_p+=2) {
        if (i % tableLen == 0) {
            tableWalker_p = table_p + 1;
        }
        memcpy(bufferWalker_p, tableWalker_p, 2);
    }
    return buffer_p;
}

class msgEncodingFixture: public ::testing::Test
{
public:
    msgEncodingFixture( )
    {
        // initialization code here
    }

    void SetUp( )
    {
    }

    void TearDown( )
    {

    }

    ~msgEncodingFixture( )
    {
        // cleanup any pending stuff, but no exceptions allowed
    }
    // put in any custom data members that you need
};

TEST_F (msgEncodingFixture, test_wchar_t)
{
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;
    wchar_t* msg = L"This is a GSM7 string";
    wchar_t* msgGSM7Ext = L"This is a {GSM7} with some extended chars[] €"; //45 chars + 5
    wchar_t* msgGSM7ESExt =
        L"This is a {GSM7ES ñ} with some extended spanish chars[] €, ú á Ú ç "; //97 chars + 9 specials (ñ is in the default table)

    if (sizeof(wchar_t) != 2) {
        printf("Platform does not have 16 bit wchar_t, test will be skipped");
        return;
    }
    sms_set_supported_encoders(ENC__GSM7 | ENC__GSM7ES | ENC__UCS2, ENC__UCS2);

    //GSM7 string
    sms_get_info((char*)msg, wcslen(msg)*sizeof(wchar_t), &noOfMessages, &charsLeft, &selectedEncoder,
                    &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 && charsLeft == (SMS_PAYLOAD_SIZE_SEPTETS-wcslen(msg)) && selectedEncoder == ENC__GSM7);

    //GSM7 string with extended chars
    sms_get_info((char*)msgGSM7Ext, wcslen(msgGSM7Ext)*sizeof(wchar_t), &noOfMessages, &charsLeft,
                    &selectedEncoder, &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 &&
                charsLeft == (SMS_PAYLOAD_SIZE_SEPTETS-(wcslen(msgGSM7Ext) +5+UDH_BASE_COST_SEPTETS
                              +UDH_COST_SINGLE_SHIFT_TABLE_SEPTETS)) && selectedEncoder == ENC__GSM7);

    //GSM7 string with extended spanish chars
    sms_get_info((char*)msgGSM7ESExt, wcslen(msgGSM7ESExt)*sizeof(wchar_t), &noOfMessages, &charsLeft,
                    &selectedEncoder, &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 &&
                charsLeft == SMS_PAYLOAD_SIZE_SEPTETS-(wcslen(msgGSM7ESExt)+9+UDH_BASE_COST_SEPTETS+UDH_COST_SINGLE_SHIFT_TABLE_SEPTETS)
                && selectedEncoder == ENC__GSM7ES);
}


TEST_F (msgEncodingFixture, testGSM7_GSM7ES_UCS2)
{
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;
    uint16_t x[5] = {0x0020, 0x0045, 0x00c1, 0x20ac, 0xff88};
    sms_set_supported_encoders(ENC__GSM7 | ENC__GSM7ES | ENC__UCS2, ENC__UCS2);
    sms_get_info((char*)&x[0], 5*sizeof(uint16_t), &noOfMessages, &charsLeft, &selectedEncoder,
                    &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 && charsLeft == 65 && selectedEncoder == ENC__UCS2);
}

TEST_F (msgEncodingFixture, testROMAN8)
{
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;
    uint16_t x[5] = {0x0020, 0x0045, 0x00c1, 0x009D, 0x25A0};
    sms_set_supported_encoders(ENC__GSM7 | ENC__GSM7ES | ENC__HP_ROMAN8 | ENC__UCS2, ENC__UCS2);
    sms_get_info((char*)&x[0], 5*sizeof(uint16_t), &noOfMessages, &charsLeft, &selectedEncoder,
                    &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 && charsLeft == 135 && selectedEncoder == ENC__HP_ROMAN8);
}

TEST_F (msgEncodingFixture, testROMAN8_1_complete_msg)
{
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;
    uint16_t buf[SMS_PAYLOAD_SIZE_OCTETS];
    uint16_t* msg = fill_16bitBuffer(buf, SMS_PAYLOAD_SIZE_OCTETS, &hp_roman8_char_set[0][0], HP_ROMAN_8_TABLE_SIZE);

    sms_set_supported_encoders(ENC__GSM7 | ENC__GSM7ES | ENC__HP_ROMAN8 | ENC__UCS2, ENC__UCS2);

    /* Fill exactly one message but include a char that GSM encoders can not handle but roman8 can
     * Msg: udh:0 bytes chars: 140 = 140 chars in the message
     */
    *(msg+1) = hp_roman8_char_set[HP_ROMAN_8_TABLE_SIZE-1][1];

    sms_get_info((char*)msg, (SMS_PAYLOAD_SIZE_OCTETS )
                    *sizeof(uint16_t), &noOfMessages, &charsLeft, &selectedEncoder, &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 && charsLeft == 0 && selectedEncoder == ENC__HP_ROMAN8);
}

TEST_F (msgEncodingFixture, testROMAN8_1_complete_msg_plus_1)
{
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;
    uint16_t buf[SMS_PAYLOAD_SIZE_OCTETS+1];
    uint16_t* msg = fill_16bitBuffer(buf, SMS_PAYLOAD_SIZE_OCTETS+1, &hp_roman8_char_set[0][0], HP_ROMAN_8_TABLE_SIZE);

    sms_set_supported_encoders(ENC__GSM7 | ENC__GSM7ES | ENC__HP_ROMAN8 | ENC__UCS2, ENC__UCS2);

    /* Fill exactly one message + 1 char using at least one hp-roman8 character. Total 141 chars to send
     * Msg1: udh=7 bytes + 133 chars
     * Msg2: udh=7 bytes + 8 chars
     * charsLeft 133-8=125
     */
    *(msg+1) = hp_roman8_char_set[HP_ROMAN_8_TABLE_SIZE-1][1];

    sms_get_info((char*)msg, (SMS_PAYLOAD_SIZE_OCTETS+1 )
                    *sizeof(uint16_t), &noOfMessages, &charsLeft, &selectedEncoder, &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 2 && charsLeft == 125 && selectedEncoder == ENC__HP_ROMAN8);
}

TEST_F (msgEncodingFixture, testROMAN8_2sms)
{
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;
    uint16_t buf[170];
    uint16_t* msg = fill_16bitBuffer(buf, 170, &hp_roman8_char_set[HP_ROMAN_8_TABLE_SIZE-170][0], HP_ROMAN_8_TABLE_SIZE);

    sms_set_supported_encoders(ENC__GSM7 | ENC__GSM7ES | ENC__HP_ROMAN8 | ENC__UCS2, ENC__UCS2);
    sms_get_info((char*)msg, 170*2, &noOfMessages, &charsLeft, &selectedEncoder, &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 2 && charsLeft == 96 && selectedEncoder == ENC__HP_ROMAN8);
}

TEST_F (msgEncodingFixture, testASCII)
{
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;
    uint16_t buf[ASCII_TABLE_SIZE];
    uint16_t* msg = fill_16bitBuffer(buf, ASCII_TABLE_SIZE, &ascii_char_set[0][0], ASCII_TABLE_SIZE);

    sms_set_supported_encoders(ENC__ASCII | ENC__UCS2, ENC__UCS2);
    sms_get_info((char*)msg, ASCII_TABLE_SIZE*2, &noOfMessages, &charsLeft, &selectedEncoder, &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 && charsLeft == 12 && selectedEncoder == ENC__ASCII);
}

TEST_F (msgEncodingFixture, testASCII_2sms)
{
#define PAYLOAD_SIZE 150
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;
    uint16_t buf[PAYLOAD_SIZE];
    uint16_t* msg = fill_16bitBuffer(buf, PAYLOAD_SIZE, &ascii_char_set[0][0], ASCII_TABLE_SIZE);

    sms_set_supported_encoders(ENC__ASCII | ENC__UCS2, ENC__UCS2);
    sms_get_info((char*)msg, PAYLOAD_SIZE*2, &noOfMessages, &charsLeft, &selectedEncoder, &selectedIsDefaultEncoder);
    //Firtst sms will contain UDH=7 bytes + 133 bytes payload. Second packet will contain the rest of the payload (17 bytes) + UDH = 7 bytes. Leaving us with 116 bytes left in the second sms.
    ASSERT_TRUE(noOfMessages == 2 && charsLeft == 116 && selectedEncoder == ENC__ASCII);
}

TEST_F (msgEncodingFixture, testLatin1)
{
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;
    uint16_t buf[LATIN1_TABLE_SIZE];
    uint16_t* msg = fill_16bitBuffer(buf, LATIN1_TABLE_SIZE, &latin1_char_set[0][0], LATIN1_TABLE_SIZE);

    sms_set_supported_encoders(ENC__ASCII | ENC__LATIN1 | ENC__UCS2, ENC__UCS2);
    sms_get_info((char*)msg, LATIN1_TABLE_SIZE*2, &noOfMessages, &charsLeft, &selectedEncoder,
                    &selectedIsDefaultEncoder);
    //Latin1 complete table = 256 chars. Each sms contains 140 - 7 bytes UDH = 133. First sms = 133 bytes data, second = 225-133 = 123 bytes data leaving 41 bytes left
    ASSERT_TRUE(noOfMessages == 2 && charsLeft == 41 && selectedEncoder == ENC__LATIN1);
}


TEST_F (msgEncodingFixture, testBorderCases)
{
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;

    sms_set_supported_encoders(ENC__GSM7 | ENC__GSM7ES | ENC__UCS2, ENC__UCS2);
    //default table
    sms_get_info((char*)&basic_char_set[0][1], 1*sizeof(uint16_t), &noOfMessages, &charsLeft, &selectedEncoder,
                    &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 && charsLeft == SMS_PAYLOAD_SIZE_SEPTETS-1 && selectedEncoder == ENC__GSM7);

    sms_get_info((char*)&basic_char_set[GSM7_TABLE_SIZE-1][1], 1*sizeof(uint16_t), &noOfMessages, &charsLeft,
                    &selectedEncoder, &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 && charsLeft == SMS_PAYLOAD_SIZE_SEPTETS-1 && selectedEncoder == ENC__GSM7);

    //Extension table (trying with spanish cahracter but first char will be picked from default table anyway)
    sms_get_info((char*)&spanish_shift_set[0][1], 1*sizeof(uint16_t), &noOfMessages, &charsLeft, &selectedEncoder,
                    &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 &&
                charsLeft == SMS_PAYLOAD_SIZE_SEPTETS - (UDH_BASE_COST_SEPTETS+UDH_COST_SINGLE_SHIFT_TABLE_SEPTETS) - 2 &&
                selectedEncoder == ENC__GSM7);

    //Spanish extension table
    sms_get_info((char*)&spanish_shift_set[SPANISH_SHIFT_SET_LEN-1][1], 1*sizeof(uint16_t), &noOfMessages, &charsLeft,
                    &selectedEncoder, &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 &&
                charsLeft == SMS_PAYLOAD_SIZE_SEPTETS - (UDH_BASE_COST_SEPTETS+UDH_COST_SINGLE_SHIFT_TABLE_SEPTETS) - 2 &&
                selectedEncoder == ENC__GSM7ES);
}


TEST_F (msgEncodingFixture, testBorderCaseOneMessage)
{
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;
    uint16_t buf[SMS_PAYLOAD_SIZE_SEPTETS];
    uint16_t* msg = fill_16bitBuffer(buf, SMS_PAYLOAD_SIZE_SEPTETS, &basic_char_set[0][0], GSM7_TABLE_SIZE);

    sms_set_supported_encoders(ENC__GSM7 | ENC__GSM7ES | ENC__HP_ROMAN8 | ENC__UCS2, ENC__UCS2);
    /* Test that using default table only 160 chars can fit in one message
     * charsLeft will be 160 since we have moved to a new fragment but this will not produce a message
     * before more characters are added.
     */
    sms_get_info(msg, SMS_PAYLOAD_SIZE_SEPTETS*sizeof(uint16_t), &noOfMessages, &charsLeft, &selectedEncoder,
                    &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 && charsLeft == 0 && selectedEncoder == ENC__GSM7);

    /* Fill one message but include an excaped char
     * Msg: udh:5 chars: 160 - 1 esc char  = 154 chars in the message
     */
    *(msg+1) = basic_char_set_extension[7][1];

    sms_get_info((char*)msg, (SMS_PAYLOAD_SIZE_SEPTETS -1 -(UDH_BASE_COST_SEPTETS+UDH_COST_SINGLE_SHIFT_TABLE_SEPTETS))
                    *sizeof(uint16_t), &noOfMessages, &charsLeft, &selectedEncoder, &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 && charsLeft == 0 && selectedEncoder == ENC__GSM7);

    /* Test using a character that can not be encoded in gsm at all
     */
    *(msg+1) = 0xbeef;
    sms_get_info((char*)msg, 70*sizeof(uint16_t), &noOfMessages, &charsLeft, &selectedEncoder,
                    &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 1 && charsLeft == 0 && selectedEncoder == ENC__UCS2);

}

/* We want to send 161 chars of the standard table
 * First msg : udh:7 chars:153
 * Second msg: udh:7 chars 8
 * charsLeft: 145
 */
TEST_F (msgEncodingFixture, testBorderCaseTwoMessages)
{
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;
    uint16_t buf[SMS_PAYLOAD_SIZE_SEPTETS+1];
    uint16_t* msg = fill_16bitBuffer(buf, SMS_PAYLOAD_SIZE_SEPTETS+1, &basic_char_set[0][0], GSM7_TABLE_SIZE);

    sms_set_supported_encoders(ENC__GSM7 | ENC__GSM7ES | ENC__UCS2, ENC__UCS2);
    sms_get_info((char*)msg, (SMS_PAYLOAD_SIZE_SEPTETS+1)*sizeof(uint16_t), &noOfMessages, &charsLeft, &selectedEncoder,
                    &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 2 && charsLeft == 145 && selectedEncoder == ENC__GSM7);

    /* Test using a character that can not be encoded in gsm or hp-roman8 at all
    * Msg1: udh:7 bytes octets left = 133 that will fit 66 UCS encoded chars
    * Msg2: udh:7 bytes octets left = 133 that can fit 66 UCS encoded chars. We will use 5 of these and there will be 61 left
    */
    *(msg+1) = 0xbeef;
    sms_get_info((char*)msg, 71*sizeof(uint16_t), &noOfMessages, &charsLeft, &selectedEncoder,
                    &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 2 && charsLeft == 61 && selectedEncoder == ENC__UCS2);
}

/* Message spanning over all GSM tables, total chars to send is:
 * 128+10+19 = 158 chars
 * 128+10*2+19*2 = 186 septets
 * First msg : udh:7 septets:153
 * Second msg: udh:7 septets: 33
 * charsLeft: 160-7-33 = 120
 */
TEST_F (msgEncodingFixture, testAllTables)
{
#define MSG_SIZE (GSM7_TABLE_SIZE + BASIC_CHAR_SET_EXT_LEN + SPANISH_SHIFT_SET_LEN)
    int noOfMessages = -1;
    int charsLeft = -1;
    int selectedEncoder = -1;
    int selectedIsDefaultEncoder = 0;
    uint16_t buf[MSG_SIZE];
    uint16_t* msg;
    int i = 0;
    char* supported_enc[3] = {"gsm7", "gsm7es", "ucs2"};
    int encoderBitmap = 0;
    for (int i =0; i < 3; i++) {
        int encoder = 0;
        sms_get_supported_encoder_mapping(supported_enc[i], &encoder);
        encoderBitmap |= encoder;
    }

    // sms_set_supported_encoders(ENC__GSM7 | ENC__GSM7ES | ENC__UCS2);

    //Stuff with default table
    msg = fill_16bitBuffer(buf, GSM7_TABLE_SIZE, &basic_char_set[0][0], GSM7_TABLE_SIZE);
    //Add extension chars
    fill_16bitBuffer(buf+GSM7_TABLE_SIZE, BASIC_CHAR_SET_EXT_LEN, &basic_char_set_extension[0][0], BASIC_CHAR_SET_EXT_LEN);
    //Add spanish extensions
    fill_16bitBuffer(buf+GSM7_TABLE_SIZE+BASIC_CHAR_SET_EXT_LEN, SPANISH_SHIFT_SET_LEN, &spanish_shift_set[0][0],
                     SPANISH_SHIFT_SET_LEN);

    sms_get_info((char*)msg, MSG_SIZE*sizeof(uint16_t), &noOfMessages, &charsLeft, &selectedEncoder,
                    &selectedIsDefaultEncoder);
    ASSERT_TRUE(noOfMessages == 2 && charsLeft == 120 && selectedEncoder == ENC__GSM7ES);
}

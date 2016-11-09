/*
 * sms_defines.h
 * A helper file with all the sms definitions we need.
 * It is mainly out in its own header to simplify unit testing
 * otherwise these values might as well be static inside the c
 * file.
 *
 *  Created on: 02/04/2013
 *      Author: johan
 */

#ifndef SMS_DEFINES_H
#define SMS_DEFINES_H
#include <stdint.h>

#define SMS_PAYLOAD_SIZE_SEPTETS    160
#define SMS_PAYLOAD_SIZE_OCTETS     140
#define SMS_PAYLOAD_SIZE_WORD        70

#define GSM7_TABLE_SIZE             128
#define HP_ROMAN_8_TABLE_SIZE       248
#define ASCII_TABLE_SIZE            128
#define LATIN1_TABLE_SIZE           225

/*GSM7->unicode. A uint16 mapping from GSM7 to unicode for the basic char set.*/
uint16_t basic_char_set[GSM7_TABLE_SIZE][2] = {
    { 0x00, 0x0040 },    /* COMMERCIAL AT */
    { 0x01, 0x00A3 },   /* POUND SIGN */
    { 0x02, 0x0024 },   /* DOLLAR SIGN */
    { 0x03, 0x00A5 },   /* YEN SIGN */
    { 0x04, 0x00E8 },   /* LATIN SMALL LETTER E WITH GRAVE */
    { 0x05, 0x00E9 }, /* LATIN SMALL LETTER E WITH ACUTE */
    { 0x06, 0x00F9 }, /* LATIN SMALL LETTER U WITH GRAVE */
    { 0x07, 0x00EC }, /* LATIN SMALL LETTER I WITH GRAVE */
    { 0x08, 0x00F2 }, /* LATIN SMALL LETTER O WITH GRAVE */
    { 0x09, 0x00C7 }, /* LATIN CAPITAL LETTER C WITH CEDILLA */
    { 0x0A, 0x000A }, /* LINE FEED */
    { 0x0B, 0x00D8 }, /* LATIN CAPITAL LETTER O WITH STROKE */
    { 0x0C, 0x00F8 }, /* LATIN SMALL LETTER O WITH STROKE */
    { 0x0D, 0x000D }, /* CARRIAGE RETURN */
    { 0x0E, 0x00C5 }, /* LATIN CAPITAL LETTER A WITH RING ABOVE */
    { 0x0F, 0x00E5 }, /* LATIN SMALL LETTER A WITH RING ABOVE */
    { 0x10, 0x0394 }, /* GREEK CAPITAL LETTER DELTA */
    { 0x11, 0x005F }, /* LOW LINE */
    { 0x12, 0x03A6 }, /* GREEK CAPITAL LETTER PHI */
    { 0x13, 0x0393 }, /* GREEK CAPITAL LETTER GAMMA */
    { 0x14, 0x039B }, /* GREEK CAPITAL LETTER LAMDA */
    { 0x15, 0x03A9 }, /* GREEK CAPITAL LETTER OMEGA */
    { 0x16, 0x03A0 }, /* GREEK CAPITAL LETTER PI */
    { 0x17, 0x03A8 }, /* GREEK CAPITAL LETTER PSI */
    { 0x18, 0x03A3 }, /* GREEK CAPITAL LETTER SIGMA */
    { 0x19, 0x0398 }, /* GREEK CAPITAL LETTER THETA */
    { 0x1A, 0x039E }, /* GREEK CAPITAL LETTER XI */
    { 0x1B, 0x00A0 }, /* ESCAPE TO EXTENSION TABLE */
    { 0x1C, 0x00C6 }, /* LATIN CAPITAL LETTER AE */
    { 0x1D, 0x00E6 }, /* LATIN SMALL LETTER AE */
    { 0x1E, 0x00DF }, /* LATIN SMALL LETTER SHARP S (German) */
    { 0x1F, 0x00C9 }, /* LATIN CAPITAL LETTER E WITH ACUTE */
    { 0x20, 0x0020 }, /* SPACE */
    { 0x21, 0x0021 }, /* EXCLAMATION MARK */
    { 0x22, 0x0022 }, /* QUOTATION MARK */
    { 0x23, 0x0023 }, /* NUMBER SIGN */
    { 0x24, 0x00A4 }, /* CURRENCY SIGN */
    { 0x25, 0x0025 }, /* PERCENT SIGN */
    { 0x26, 0x0026 }, /* AMPERSAND */
    { 0x27, 0x0027 }, /* APOSTROPHE */
    { 0x28, 0x0028 }, /* LEFT PARENTHESIS */
    { 0x29, 0x0029 }, /* RIGHT PARENTHESIS */
    { 0x2A, 0x002A }, /* ASTERISK */
    { 0x2B, 0x002B }, /* PLUS SIGN */
    { 0x2C, 0x002C }, /* COMMA */
    { 0x2D, 0x002D }, /* HYPHEN-MINUS */
    { 0x2E, 0x002E }, /* FULL STOP */
    { 0x2F, 0x002F }, /* SOLIDUS */
    { 0x30, 0x0030 }, /* DIGIT ZERO */
    { 0x31, 0x0031 }, /* DIGIT ONE */
    { 0x32, 0x0032 }, /* DIGIT TWO */
    { 0x33, 0x0033 }, /* DIGIT THREE */
    { 0x34, 0x0034 }, /* DIGIT FOUR */
    { 0x35, 0x0035 }, /* DIGIT FIVE */
    { 0x36, 0x0036 }, /* DIGIT SIX */
    { 0x37, 0x0037 }, /* DIGIT SEVEN */
    { 0x38, 0x0038 }, /* DIGIT EIGHT */
    { 0x39, 0x0039 }, /* DIGIT NINE */
    { 0x3A, 0x003A }, /* COLON */
    { 0x3B, 0x003B }, /* SEMICOLON */
    { 0x3C, 0x003C }, /* LESS-THAN SIGN */
    { 0x3D, 0x003D }, /* EQUALS SIGN */
    { 0x3E, 0x003E }, /* GREATER-THAN SIGN */
    { 0x3F, 0x003F }, /* QUESTION MARK */
    { 0x40, 0x00A1 }, /* INVERTED EXCLAMATION MARK */
    { 0x41, 0x0041 }, /* LATIN CAPITAL LETTER A */
    { 0x42, 0x0042 }, /* LATIN CAPITAL LETTER B */
    { 0x43, 0x0043 }, /* LATIN CAPITAL LETTER C */
    { 0x44, 0x0044 }, /* LATIN CAPITAL LETTER D */
    { 0x45, 0x0045 }, /* LATIN CAPITAL LETTER E */
    { 0x46, 0x0046 }, /* LATIN CAPITAL LETTER F */
    { 0x47, 0x0047 }, /* LATIN CAPITAL LETTER G */
    { 0x48, 0x0048 }, /* LATIN CAPITAL LETTER H */
    { 0x49, 0x0049 }, /* LATIN CAPITAL LETTER I */
    { 0x4A, 0x004A }, /* LATIN CAPITAL LETTER J */
    { 0x4B, 0x004B }, /* LATIN CAPITAL LETTER K */
    { 0x4C, 0x004C }, /* LATIN CAPITAL LETTER L */
    { 0x4D, 0x004D }, /* LATIN CAPITAL LETTER M */
    { 0x4E, 0x004E }, /* LATIN CAPITAL LETTER N */
    { 0x4F, 0x004F }, /* LATIN CAPITAL LETTER O */
    { 0x50, 0x0050 }, /* LATIN CAPITAL LETTER P */
    { 0x51, 0x0051 }, /* LATIN CAPITAL LETTER Q */
    { 0x52, 0x0052 }, /* LATIN CAPITAL LETTER R */
    { 0x53, 0x0053 }, /* LATIN CAPITAL LETTER S */
    { 0x54, 0x0054 }, /* LATIN CAPITAL LETTER T */
    { 0x55, 0x0055 }, /* LATIN CAPITAL LETTER U */
    { 0x56, 0x0056 }, /* LATIN CAPITAL LETTER V */
    { 0x57, 0x0057 }, /* LATIN CAPITAL LETTER W */
    { 0x58, 0x0058 }, /* LATIN CAPITAL LETTER X */
    { 0x59, 0x0059 }, /* LATIN CAPITAL LETTER Y */
    { 0x5A, 0x005A }, /* LATIN CAPITAL LETTER Z */
    { 0x5B, 0x00C4 }, /* LATIN CAPITAL LETTER A WITH DIAERESIS */
    { 0x5C, 0x00D6 }, /* LATIN CAPITAL LETTER O WITH DIAERESIS */
    { 0x5D, 0x00D1 }, /* LATIN CAPITAL LETTER N WITH TILDE */
    { 0x5E, 0x00DC }, /* LATIN CAPITAL LETTER U WITH DIAERESIS */
    { 0x5F, 0x00A7 }, /* SECTION SIGN */
    { 0x60, 0x00BF }, /* INVERTED QUESTION MARK */
    { 0x61, 0x0061 }, /* LATIN SMALL LETTER A */
    { 0x62, 0x0062 }, /* LATIN SMALL LETTER B */
    { 0x63, 0x0063 }, /* LATIN SMALL LETTER C */
    { 0x64, 0x0064 }, /* LATIN SMALL LETTER D */
    { 0x65, 0x0065 }, /* LATIN SMALL LETTER E */
    { 0x66, 0x0066 }, /* LATIN SMALL LETTER F */
    { 0x67, 0x0067 }, /* LATIN SMALL LETTER G */
    { 0x68, 0x0068 }, /* LATIN SMALL LETTER H */
    { 0x69, 0x0069 }, /* LATIN SMALL LETTER I */
    { 0x6A, 0x006A }, /* LATIN SMALL LETTER J */
    { 0x6B, 0x006B }, /* LATIN SMALL LETTER K */
    { 0x6C, 0x006C }, /* LATIN SMALL LETTER L */
    { 0x6D, 0x006D }, /* LATIN SMALL LETTER M */
    { 0x6E, 0x006E }, /* LATIN SMALL LETTER N */
    { 0x6F, 0x006F }, /* LATIN SMALL LETTER O */
    { 0x70, 0x0070 }, /* LATIN SMALL LETTER P */
    { 0x71, 0x0071 }, /* LATIN SMALL LETTER Q */
    { 0x72, 0x0072 }, /* LATIN SMALL LETTER R */
    { 0x73, 0x0073 }, /* LATIN SMALL LETTER S */
    { 0x74, 0x0074 }, /* LATIN SMALL LETTER T */
    { 0x75, 0x0075 }, /* LATIN SMALL LETTER U */
    { 0x76, 0x0076 }, /* LATIN SMALL LETTER V */
    { 0x77, 0x0077 }, /* LATIN SMALL LETTER W */
    { 0x78, 0x0078 }, /* LATIN SMALL LETTER X */
    { 0x79, 0x0079 }, /* LATIN SMALL LETTER Y */
    { 0x7A, 0x007A }, /* LATIN SMALL LETTER Z */
    { 0x7B, 0x00E4 }, /* LATIN SMALL LETTER A WITH DIAERESIS */
    { 0x7C, 0x00F6 }, /* LATIN SMALL LETTER O WITH DIAERESIS */
    { 0x7D, 0x00F1 }, /* LATIN SMALL LETTER N WITH TILDE */
    { 0x7E, 0x00FC }, /* LATIN SMALL LETTER U WITH DIAERESIS */
    { 0x7F, 0x00E0 }  /* LATIN SMALL LETTER A WITH GRAVE */
};

/*GSM7_to_unicode to unicode mapping for basic char set extensions.*/
#define BASIC_CHAR_SET_EXT_LEN        10
uint16_t basic_char_set_extension[BASIC_CHAR_SET_EXT_LEN][2] = {
    { 0x0A, 0x000C },   /* FORM FEED */
    { 0x14, 0x005E },   /* CIRCUMFLEX ACCENT */
    { 0x28, 0x007B },   /* LEFT CURLY BRACKET */
    { 0x29, 0x007D },   /* RIGHT CURLY BRACKET */
    { 0x2F, 0x005C },   /* REVERSE SOLIDUS */
    { 0x3C, 0x005B },   /* LEFT SQUARE BRACKET */
    { 0x3D, 0x007E },   /* TILDE */
    { 0x3E, 0x005D },   /* RIGHT SQUARE BRACKET */
    { 0x40, 0x007C },   /* VERTICAL LINE */
    { 0x65, 0x20AC }    /* EURO SIGN */
};

/*GSM7_to_unicode to unicode mapping for basic char set extensions.*/
#define SPANISH_SHIFT_SET_LEN        19
uint16_t spanish_shift_set[SPANISH_SHIFT_SET_LEN][2] = {
    /*The basic char set part*/
    { 0x0A, 0x000C },   /* FORM FEED */
    { 0x14, 0x005E },   /* CIRCUMFLEX ACCENT */
    { 0x28, 0x007B },   /* LEFT CURLY BRACKET */
    { 0x29, 0x007D },   /* RIGHT CURLY BRACKET */
    { 0x2F, 0x005C },   /* REVERSE SOLIDUS */
    { 0x3C, 0x005B },   /* LEFT SQUARE BRACKET */
    { 0x3D, 0x007E },   /* TILDE */
    { 0x3E, 0x005D },   /* RIGHT SQUARE BRACKET */
    { 0x40, 0x007C },   /* VERTICAL LINE */
    { 0x65, 0x20AC },   /* EURO SIGN */
    /*The spanish additions*/
    { 0x09, 0x00E7 },    /* SMALL C WITH CEDILLA */
    { 0x41, 0x00C1 },    /* CAPITAL A WITH ACUTE */
    { 0x49, 0x00CD },    /* CAPITAL I WITH ACUTE */
    { 0x4F, 0x00D3 },    /* CAPITAL O WITH ACUTE */
    { 0x55, 0x00DA },    /* CAPITAL U WITH ACUTE */
    { 0x61, 0x00E1 },    /* SMALL A WITH ACUTE */
    { 0x69, 0x00ED },    /* SMALL I WITH ACUTE */
    { 0x6F, 0x00F3 },    /* SMALL O WITH ACUTE */
    { 0x75, 0x00FA }     /* SMALL U WITH ACUTE */
};

/*HPRoman8->unicode. A uint16 mapping from GSM7 to unicode for the basic char set (http://www.fileformat.info/info/charset/hp-roman8/list.htm) */
uint16_t hp_roman8_char_set[HP_ROMAN_8_TABLE_SIZE][2] = {
    { 0x00, 0x0000 },   /* NULL */
    { 0x01, 0x0001 },   /* START OF HEADING */
    { 0x02, 0x0002 },   /* START OF TEXT */
    { 0x03, 0x0003 },   /* END OF TEXT */
    { 0x04, 0x0004 },   /* END OF TRANSMISSION */
    { 0x05, 0x0005 }, /* ENQUIRY */
    { 0x06, 0x0006 }, /* ACKNOWLEDGE */
    { 0x07, 0x0007 }, /* BELL */
    { 0x08, 0x0008 }, /* BACKSPACE */
    { 0x09, 0x0009 }, /* CHARACTER TABULATION */
    { 0x0A, 0x000A }, /* LINE FEED */
    { 0x0B, 0x000B }, /* LINE TABULATION */
    { 0x0C, 0x000C }, /* FORM FEED */
    { 0x0D, 0x000D }, /* CARRIAGE RETURN */
    { 0x0E, 0x000E }, /* SHIFT OUT */
    { 0x0F, 0x000F }, /* SHIFT IN */
    { 0x10, 0x0010 }, /* DATA LINK ESCAPE */
    { 0x11, 0x0011 }, /* DEVICE CONTROL ONE */
    { 0x12, 0x0012 }, /* DEVICE CONTROL TWO */
    { 0x13, 0x0013 }, /* DEVICE CONTROL THREE */
    { 0x14, 0x0014 }, /* DEVICE CONTROL FOUR */
    { 0x15, 0x0015 }, /* NEGATIVE ACK */
    { 0x16, 0x0016 }, /* SYNC IDLE */
    { 0x17, 0x0017 }, /* END OF TRANSMISSION */
    { 0x18, 0x0018 }, /* CANCEL */
    { 0x19, 0x0019 }, /* END OF MEDIUM */
    { 0x1A, 0x001A }, /* SUBSTITUTE */
    { 0x1B, 0x001B }, /* ESCAPE */
    { 0x1C, 0x001C }, /* INF SEP FOUR */
    { 0x1D, 0x001D }, /* INF SEP THREE */
    { 0x1E, 0x001E }, /* INF SEP TWO */
    { 0x1F, 0x001F }, /* INF SEP ONE */
    { 0x20, 0x0020 }, /* SPACE */
    { 0x21, 0x0021 }, /* EXCLAMATION MARK */
    { 0x22, 0x0022 }, /* QUOTATION MARK */
    { 0x23, 0x0023 }, /* NUMBER SIGN */
    { 0x24, 0x0024 }, /* CURRENCY SIGN */
    { 0x25, 0x0025 }, /* PERCENT SIGN */
    { 0x26, 0x0026 }, /* AMPERSAND */
    { 0x27, 0x0027 }, /* APOSTROPHE */
    { 0x28, 0x0028 }, /* LEFT PARENTHESIS */
    { 0x29, 0x0029 }, /* RIGHT PARENTHESIS */
    { 0x2A, 0x002A }, /* ASTERISK */
    { 0x2B, 0x002B }, /* PLUS SIGN */
    { 0x2C, 0x002C }, /* COMMA */
    { 0x2D, 0x002D }, /* HYPHEN-MINUS */
    { 0x2E, 0x002E }, /* FULL STOP */
    { 0x2F, 0x002F }, /* SOLIDUS */
    { 0x30, 0x0030 }, /* DIGIT ZERO */
    { 0x31, 0x0031 }, /* DIGIT ONE */
    { 0x32, 0x0032 }, /* DIGIT TWO */
    { 0x33, 0x0033 }, /* DIGIT THREE */
    { 0x34, 0x0034 }, /* DIGIT FOUR */
    { 0x35, 0x0035 }, /* DIGIT FIVE */
    { 0x36, 0x0036 }, /* DIGIT SIX */
    { 0x37, 0x0037 }, /* DIGIT SEVEN */
    { 0x38, 0x0038 }, /* DIGIT EIGHT */
    { 0x39, 0x0039 }, /* DIGIT NINE */
    { 0x3A, 0x003A }, /* COLON */
    { 0x3B, 0x003B }, /* SEMICOLON */
    { 0x3C, 0x003C }, /* LESS-THAN SIGN */
    { 0x3D, 0x003D }, /* EQUALS SIGN */
    { 0x3E, 0x003E }, /* GREATER-THAN SIGN */
    { 0x3F, 0x003F }, /* QUESTION MARK */
    { 0x40, 0x0040 }, /* COMMERCIAL AT */
    { 0x41, 0x0041 }, /* LATIN CAPITAL LETTER A */
    { 0x42, 0x0042 }, /* LATIN CAPITAL LETTER B */
    { 0x43, 0x0043 }, /* LATIN CAPITAL LETTER C */
    { 0x44, 0x0044 }, /* LATIN CAPITAL LETTER D */
    { 0x45, 0x0045 }, /* LATIN CAPITAL LETTER E */
    { 0x46, 0x0046 }, /* LATIN CAPITAL LETTER F */
    { 0x47, 0x0047 }, /* LATIN CAPITAL LETTER G */
    { 0x48, 0x0048 }, /* LATIN CAPITAL LETTER H */
    { 0x49, 0x0049 }, /* LATIN CAPITAL LETTER I */
    { 0x4A, 0x004A }, /* LATIN CAPITAL LETTER J */
    { 0x4B, 0x004B }, /* LATIN CAPITAL LETTER K */
    { 0x4C, 0x004C }, /* LATIN CAPITAL LETTER L */
    { 0x4D, 0x004D }, /* LATIN CAPITAL LETTER M */
    { 0x4E, 0x004E }, /* LATIN CAPITAL LETTER N */
    { 0x4F, 0x004F }, /* LATIN CAPITAL LETTER O */
    { 0x50, 0x0050 }, /* LATIN CAPITAL LETTER P */
    { 0x51, 0x0051 }, /* LATIN CAPITAL LETTER Q */
    { 0x52, 0x0052 }, /* LATIN CAPITAL LETTER R */
    { 0x53, 0x0053 }, /* LATIN CAPITAL LETTER S */
    { 0x54, 0x0054 }, /* LATIN CAPITAL LETTER T */
    { 0x55, 0x0055 }, /* LATIN CAPITAL LETTER U */
    { 0x56, 0x0056 }, /* LATIN CAPITAL LETTER V */
    { 0x57, 0x0057 }, /* LATIN CAPITAL LETTER W */
    { 0x58, 0x0058 }, /* LATIN CAPITAL LETTER X */
    { 0x59, 0x0059 }, /* LATIN CAPITAL LETTER Y */
    { 0x5A, 0x005A }, /* LATIN CAPITAL LETTER Z */
    { 0x5B, 0x005B }, /* LEFT SQUARE BRACKET */
    { 0x5C, 0x005C }, /* REVERSE SOLIDUS */
    { 0x5D, 0x005D }, /* RIGHT SQUARE BRACKET */
    { 0x5E, 0x005E }, /* CIRCUMFLEX ACCENT */
    { 0x5F, 0x005F }, /* LOW LINE */
    { 0x60, 0x0060 }, /* GRAVE ACCENT */
    { 0x61, 0x0061 }, /* LATIN SMALL LETTER A */
    { 0x62, 0x0062 }, /* LATIN SMALL LETTER B */
    { 0x63, 0x0063 }, /* LATIN SMALL LETTER C */
    { 0x64, 0x0064 }, /* LATIN SMALL LETTER D */
    { 0x65, 0x0065 }, /* LATIN SMALL LETTER E */
    { 0x66, 0x0066 }, /* LATIN SMALL LETTER F */
    { 0x67, 0x0067 }, /* LATIN SMALL LETTER G */
    { 0x68, 0x0068 }, /* LATIN SMALL LETTER H */
    { 0x69, 0x0069 }, /* LATIN SMALL LETTER I */
    { 0x6A, 0x006A }, /* LATIN SMALL LETTER J */
    { 0x6B, 0x006B }, /* LATIN SMALL LETTER K */
    { 0x6C, 0x006C }, /* LATIN SMALL LETTER L */
    { 0x6D, 0x006D }, /* LATIN SMALL LETTER M */
    { 0x6E, 0x006E }, /* LATIN SMALL LETTER N */
    { 0x6F, 0x006F }, /* LATIN SMALL LETTER O */
    { 0x70, 0x0070 }, /* LATIN SMALL LETTER P */
    { 0x71, 0x0071 }, /* LATIN SMALL LETTER Q */
    { 0x72, 0x0072 }, /* LATIN SMALL LETTER R */
    { 0x73, 0x0073 }, /* LATIN SMALL LETTER S */
    { 0x74, 0x0074 }, /* LATIN SMALL LETTER T */
    { 0x75, 0x0075 }, /* LATIN SMALL LETTER U */
    { 0x76, 0x0076 }, /* LATIN SMALL LETTER V */
    { 0x77, 0x0077 }, /* LATIN SMALL LETTER W */
    { 0x78, 0x0078 }, /* LATIN SMALL LETTER X */
    { 0x79, 0x0079 }, /* LATIN SMALL LETTER Y */
    { 0x7A, 0x007A }, /* LATIN SMALL LETTER Z */
    { 0x7B, 0x007B }, /* LEFT CURLY BRACKET */
    { 0x7C, 0x007C }, /* VERTICAL LINE */
    { 0x7D, 0x007D }, /* RIGHT CURLY BRACKET */
    { 0x7E, 0x007E }, /* TILDE */
    { 0x7F, 0x007F },  /* DELETE */
    { 0x80, 0x0080 }, /* control */
    { 0x81, 0x0081 }, /* control */
    { 0x82, 0x0082 }, /* BREAK PERMITTED HERE */
    { 0x83, 0x0083 }, /* NO BREAK HERE */
    { 0x84, 0x0084 }, /* control */
    { 0x85, 0x0085 }, /* NEXT LINE */
    { 0x86, 0x0086 }, /* START OF SELECTED AREA */
    { 0x87, 0x0087 }, /* END OF SELECTED AREA */
    { 0x88, 0x0088 }, /* CHARACTER TAB SET */
    { 0x89, 0x0089 }, /* CHARACTER TAB SET WITH JUSTIFICATION */
    { 0x8A, 0x008A }, /* LINE TAB SET */
    { 0x8B, 0x008B }, /* PARTIAL LINE FORWARD */
    { 0x8C, 0x008C }, /* PARTIAL LINE BACKWARD */
    { 0x8D, 0x008D }, /* REVERSE LINE FEED */
    { 0x8E, 0x008E }, /* SINGLE SHIFT TWO*/
    { 0x8F, 0x008F },  /* SINGLE SHIFT THREE */
    { 0x90, 0x0090 }, /* DEVICE CONTROL STRING */
    { 0x91, 0x0091 }, /* PRIVATE USE ONE */
    { 0x92, 0x0092 }, /* PRIVATE USE TWO */
    { 0x93, 0x0093 }, /* SET TRANSMIT STATE */
    { 0x94, 0x0094 }, /* CANCEL CHARACTER */
    { 0x95, 0x0095 }, /* MESSAGE WAITING */
    { 0x96, 0x0096 }, /* START OF GUARDED AREA */
    { 0x97, 0x0097 }, /* END OF GUARDED AREA */
    { 0x98, 0x0098 }, /* START OF STRING */
    { 0x99, 0x0099 }, /* control */
    { 0x9A, 0x009A }, /* SINGLE CHARACTER INTRODUCER */
    { 0x9B, 0x009B }, /* CONTROL SEQUENCE INTRODUCER */
    { 0x9C, 0x009C }, /* STRING TERMINATOR */
    { 0x9D, 0x009D }, /* OPERATING SYSTEM COMMAND */
    { 0x9E, 0x009E }, /* PRIVACY MESSAGE*/
    { 0x9F, 0x009F },  /* APPLICATION PROGRAM COMMAND */
    { 0xA0, 0x00A0 }, /* NO BREAK SPACE */
    { 0xBA, 0x00A4 }, /* CURRECNY SIGN */
    { 0xBC, 0x00A5 }, /* YEN SIGN */
    { 0xBD, 0x00A7 }, /* SECTION SIGN */
    { 0xAB, 0x00A8 }, /* DIARESEIS */
    { 0xF9, 0x00AA }, /* FEMALE ORDINAL INDICATOR */
    { 0xFB, 0x00AB }, /* LEFT POINT DOUBLE ANGLE */
    { 0xB0, 0x00AF }, /* MACRON */
    { 0xB3, 0x00B0 }, /* DEGREE SIGN */
    { 0xFE, 0x00B1 }, /* PLUS MINUS SIGN */
    { 0xA8, 0x00B4 }, /* ACUTE ACCENT */
    { 0xF3, 0x00B5 }, /* MICRO SIGN */
    { 0xF4, 0x00B6 }, /* PILCROW SIGN */
    { 0xF2, 0x00B7 }, /* MIDDLE DOT */
    { 0xFA, 0x00BA }, /* MASC ORDINAL INDICATOR */
    { 0xFD, 0x00BB }, /* RIGHT POINT DOUBLE ANGLE QUOTATION */
    { 0xF7, 0x00BC }, /* VULGAR */
    { 0xf8, 0x00BD }, /* VULGAR HALF */
    { 0xF5, 0x00BE }, /* VULGAR 3/4 */
    { 0xB9, 0x00BF }, /* INVERTED QUESTION MARK */
    { 0xA1, 0x00C0 }, /* A WITH GRAVE */
    { 0xE0, 0x00C1 }, /* A WITH ACUTE */
    { 0xA2, 0x00C2 }, /* A WITH CICRUMFLEX */
    { 0xE1, 0x00C3 }, /* A WITH TILDE */
    { 0xD8, 0x00C4 }, /* A WITH DIARESEIS */
    { 0xD0, 0x00C5 }, /* A WITH RING ABOVE */
    { 0xD3, 0x00C6 }, /* AE */
    { 0xB4, 0x00C7 }, /* C WITH CEDILLA */
    { 0xA3, 0x00C8 }, /* E WITH GRAVE */
    { 0xDC, 0x00C9 }, /* E WITH ACUTE */
    { 0xA4, 0x00CA }, /* E WITH CIRCUMFLEX */
    { 0xA5, 0x00CB }, /* E WITH DIARESEIS  */
    { 0xE6, 0x00CC }, /* I WITH GRAVE */
    { 0xE5, 0x00CD }, /* I WITH ACUTE */
    { 0xA6, 0x00CE }, /* I WITH CIRCUMFLEX */
    { 0xA7, 0x00CF }, /* I WITH DIARESEIS */
    { 0xE3, 0x00D0 }, /* ETH */
    { 0xB6, 0x00D1 }, /* N WITH TILDE */
    { 0xE8, 0x00D2 }, /* O WITH GRAVE */
    { 0xE7, 0x00D3 }, /* O WITH ACUTE */
    { 0xDF, 0x00D4 }, /* O WITH CIRCUMFLEX */
    { 0xE9, 0x00D5 }, /* O WITH TILDE */
    { 0xDA, 0x00D6 }, /* O WITH DIARESIS */
    { 0xD2, 0x00D8 }, /* O WITH STROKE */
    { 0xED, 0x00DA }, /* U WITH ACUTE */
    { 0xAE, 0x00DB }, /* U WITH CIRCUMFLEX */
    { 0xDB, 0x00DC }, /* U WITH DIARESIS */
    { 0xB1, 0x00DD }, /* Y WITH ACUTE */
    { 0xF0, 0x00DE }, /* THORN */
    { 0xDE, 0x00DF }, /* SMALL SHARP S */
    { 0xC8, 0x00E0 }, /* SMALL A WITH GRAVE */
    { 0xC4, 0x00E1 }, /* SMALL A WITH ACUTE */
    { 0xC0, 0x00E2 }, /* SMALL A WITH CIRCUMFLEX */
    { 0xE2, 0x00E3 }, /* SMALL A WITH TILDE */
    { 0xCC, 0x00E4 }, /* SMALL A WITH DIARESIS */
    { 0xD4, 0x00E5 }, /* SMALL A WITH RING ABOVE */
    { 0xD7, 0x00E6 }, /* SMALL AE */
    { 0xB5, 0x00E7 }, /* SMALL C WITH CEDILLA */
    { 0xC9, 0x00E8 }, /* SMALL E WITH GRAVE */
    { 0xC5, 0x00E9 }, /* SMALL E WITH ACUTE */
    { 0xC1, 0x00EA }, /* SMALL E WITH CIRCUMFLEX */
    { 0xCD, 0x00EB }, /* SMALL E WITH DIARESIS */
    { 0xD9, 0x00EC }, /* SMALL I WITH GRAVE */
    { 0xD5, 0x00ED }, /* SMALL I WITH ACUTE */
    { 0xD1, 0x00EE }, /* SMALL I WITH CICRUMFLEX */
    { 0xDD, 0x00EF }, /* SMALL I WITH DIARESIS */
    { 0xE4, 0x00F0 }, /* SMALL ETH */
    { 0xB7, 0x00F1 }, /* SMALL N WITH TILDE */
    { 0xCA, 0x00F2 }, /* SMALL O WITH GRAVE */
    { 0xC6, 0x00F3 }, /* SMALL O WITH ACUTE */
    { 0xC2, 0x00F4 }, /* SMALL O WITH CIRCUMFLEX */
    { 0xEA, 0x00F5 }, /* SMALL O WITH TILDE */
    { 0xCE, 0x00F6 }, /* SMALL O WITH DIARESIS */
    { 0xD6, 0x00F8 }, /* SMALL O WITH STROKE */
    { 0xCB, 0x00F9 }, /* SMALL U WITH GRAVE */
    { 0xC7, 0x00FA }, /* SMALL U WITH ACUTE */
    { 0xC3, 0x00FB }, /* SMALL U WITH CIRCUMFLEX */
    { 0xCF, 0x00FC }, /* SMALL U WITH DIARESIS */
    { 0xB2, 0x00FD }, /* SMALL Y WITH ACUTE */
    { 0xF1, 0x00FE }, /* SMALL THORN */
    { 0xEF, 0x00FF }, /* SMALL Y WITH DIARESIS */
    { 0xEB, 0x0160 }, /* S WITH CARON */
    { 0xEC, 0x0161 }, /* SMALL S WITH CARON */
    { 0xEE, 0x0178 }, /* Y WITH DIARESIS */
    { 0xBE, 0x0192 }, /* SMALL F WITH HOOK */
    { 0xF6, 0x2014 }, /* EM DASH */
    { 0xAF, 0x20A4 }, /* LIRA SIGN */
    { 0xFC, 0x25A0 } /* BLACK SQUARE */
};

/*ASCII->unicode. These two are actually 100% compatible so its a 1-1 mapping */
uint16_t ascii_char_set[ASCII_TABLE_SIZE][2] = {
    { 0x00, 0x0000 },   /* NULL */
    { 0x01, 0x0001 },   /* START OF HEADING */
    { 0x02, 0x0002 },   /* START OF TEXT */
    { 0x03, 0x0003 },   /* END OF TEXT */
    { 0x04, 0x0004 },   /* END OF TRANSMISSION */
    { 0x05, 0x0005 }, /* ENQUIRY */
    { 0x06, 0x0006 }, /* ACKNOWLEDGE */
    { 0x07, 0x0007 }, /* BELL */
    { 0x08, 0x0008 }, /* BACKSPACE */
    { 0x09, 0x0009 }, /* CHARACTER TABULATION */
    { 0x0A, 0x000A }, /* LINE FEED */
    { 0x0B, 0x000B }, /* LINE TABULATION */
    { 0x0C, 0x000C }, /* FORM FEED */
    { 0x0D, 0x000D }, /* CARRIAGE RETURN */
    { 0x0E, 0x000E }, /* SHIFT OUT */
    { 0x0F, 0x000F }, /* SHIFT IN */
    { 0x10, 0x0010 }, /* DATA LINK ESCAPE */
    { 0x11, 0x0011 }, /* DEVICE CONTROL ONE */
    { 0x12, 0x0012 }, /* DEVICE CONTROL TWO */
    { 0x13, 0x0013 }, /* DEVICE CONTROL THREE */
    { 0x14, 0x0014 }, /* DEVICE CONTROL FOUR */
    { 0x15, 0x0015 }, /* NEGATIVE ACK */
    { 0x16, 0x0016 }, /* SYNC IDLE */
    { 0x17, 0x0017 }, /* END OF TRANSMISSION */
    { 0x18, 0x0018 }, /* CANCEL */
    { 0x19, 0x0019 }, /* END OF MEDIUM */
    { 0x1A, 0x001A }, /* SUBSTITUTE */
    { 0x1B, 0x001B }, /* ESCAPE */
    { 0x1C, 0x001C }, /* INF SEP FOUR */
    { 0x1D, 0x001D }, /* INF SEP THREE */
    { 0x1E, 0x001E }, /* INF SEP TWO */
    { 0x1F, 0x001F }, /* INF SEP ONE */
    { 0x20, 0x0020 }, /* SPACE */
    { 0x21, 0x0021 }, /* EXCLAMATION MARK */
    { 0x22, 0x0022 }, /* QUOTATION MARK */
    { 0x23, 0x0023 }, /* NUMBER SIGN */
    { 0x24, 0x0024 }, /* CURRENCY SIGN */
    { 0x25, 0x0025 }, /* PERCENT SIGN */
    { 0x26, 0x0026 }, /* AMPERSAND */
    { 0x27, 0x0027 }, /* APOSTROPHE */
    { 0x28, 0x0028 }, /* LEFT PARENTHESIS */
    { 0x29, 0x0029 }, /* RIGHT PARENTHESIS */
    { 0x2A, 0x002A }, /* ASTERISK */
    { 0x2B, 0x002B }, /* PLUS SIGN */
    { 0x2C, 0x002C }, /* COMMA */
    { 0x2D, 0x002D }, /* HYPHEN-MINUS */
    { 0x2E, 0x002E }, /* FULL STOP */
    { 0x2F, 0x002F }, /* SOLIDUS */
    { 0x30, 0x0030 }, /* DIGIT ZERO */
    { 0x31, 0x0031 }, /* DIGIT ONE */
    { 0x32, 0x0032 }, /* DIGIT TWO */
    { 0x33, 0x0033 }, /* DIGIT THREE */
    { 0x34, 0x0034 }, /* DIGIT FOUR */
    { 0x35, 0x0035 }, /* DIGIT FIVE */
    { 0x36, 0x0036 }, /* DIGIT SIX */
    { 0x37, 0x0037 }, /* DIGIT SEVEN */
    { 0x38, 0x0038 }, /* DIGIT EIGHT */
    { 0x39, 0x0039 }, /* DIGIT NINE */
    { 0x3A, 0x003A }, /* COLON */
    { 0x3B, 0x003B }, /* SEMICOLON */
    { 0x3C, 0x003C }, /* LESS-THAN SIGN */
    { 0x3D, 0x003D }, /* EQUALS SIGN */
    { 0x3E, 0x003E }, /* GREATER-THAN SIGN */
    { 0x3F, 0x003F }, /* QUESTION MARK */
    { 0x40, 0x0040 }, /* COMMERCIAL AT */
    { 0x41, 0x0041 }, /* LATIN CAPITAL LETTER A */
    { 0x42, 0x0042 }, /* LATIN CAPITAL LETTER B */
    { 0x43, 0x0043 }, /* LATIN CAPITAL LETTER C */
    { 0x44, 0x0044 }, /* LATIN CAPITAL LETTER D */
    { 0x45, 0x0045 }, /* LATIN CAPITAL LETTER E */
    { 0x46, 0x0046 }, /* LATIN CAPITAL LETTER F */
    { 0x47, 0x0047 }, /* LATIN CAPITAL LETTER G */
    { 0x48, 0x0048 }, /* LATIN CAPITAL LETTER H */
    { 0x49, 0x0049 }, /* LATIN CAPITAL LETTER I */
    { 0x4A, 0x004A }, /* LATIN CAPITAL LETTER J */
    { 0x4B, 0x004B }, /* LATIN CAPITAL LETTER K */
    { 0x4C, 0x004C }, /* LATIN CAPITAL LETTER L */
    { 0x4D, 0x004D }, /* LATIN CAPITAL LETTER M */
    { 0x4E, 0x004E }, /* LATIN CAPITAL LETTER N */
    { 0x4F, 0x004F }, /* LATIN CAPITAL LETTER O */
    { 0x50, 0x0050 }, /* LATIN CAPITAL LETTER P */
    { 0x51, 0x0051 }, /* LATIN CAPITAL LETTER Q */
    { 0x52, 0x0052 }, /* LATIN CAPITAL LETTER R */
    { 0x53, 0x0053 }, /* LATIN CAPITAL LETTER S */
    { 0x54, 0x0054 }, /* LATIN CAPITAL LETTER T */
    { 0x55, 0x0055 }, /* LATIN CAPITAL LETTER U */
    { 0x56, 0x0056 }, /* LATIN CAPITAL LETTER V */
    { 0x57, 0x0057 }, /* LATIN CAPITAL LETTER W */
    { 0x58, 0x0058 }, /* LATIN CAPITAL LETTER X */
    { 0x59, 0x0059 }, /* LATIN CAPITAL LETTER Y */
    { 0x5A, 0x005A }, /* LATIN CAPITAL LETTER Z */
    { 0x5B, 0x005B }, /* LEFT SQUARE BRACKET */
    { 0x5C, 0x005C }, /* REVERSE SOLIDUS */
    { 0x5D, 0x005D }, /* RIGHT SQUARE BRACKET */
    { 0x5E, 0x005E }, /* CIRCUMFLEX ACCENT */
    { 0x5F, 0x005F }, /* LOW LINE */
    { 0x60, 0x0060 }, /* GRAVE ACCENT */
    { 0x61, 0x0061 }, /* LATIN SMALL LETTER A */
    { 0x62, 0x0062 }, /* LATIN SMALL LETTER B */
    { 0x63, 0x0063 }, /* LATIN SMALL LETTER C */
    { 0x64, 0x0064 }, /* LATIN SMALL LETTER D */
    { 0x65, 0x0065 }, /* LATIN SMALL LETTER E */
    { 0x66, 0x0066 }, /* LATIN SMALL LETTER F */
    { 0x67, 0x0067 }, /* LATIN SMALL LETTER G */
    { 0x68, 0x0068 }, /* LATIN SMALL LETTER H */
    { 0x69, 0x0069 }, /* LATIN SMALL LETTER I */
    { 0x6A, 0x006A }, /* LATIN SMALL LETTER J */
    { 0x6B, 0x006B }, /* LATIN SMALL LETTER K */
    { 0x6C, 0x006C }, /* LATIN SMALL LETTER L */
    { 0x6D, 0x006D }, /* LATIN SMALL LETTER M */
    { 0x6E, 0x006E }, /* LATIN SMALL LETTER N */
    { 0x6F, 0x006F }, /* LATIN SMALL LETTER O */
    { 0x70, 0x0070 }, /* LATIN SMALL LETTER P */
    { 0x71, 0x0071 }, /* LATIN SMALL LETTER Q */
    { 0x72, 0x0072 }, /* LATIN SMALL LETTER R */
    { 0x73, 0x0073 }, /* LATIN SMALL LETTER S */
    { 0x74, 0x0074 }, /* LATIN SMALL LETTER T */
    { 0x75, 0x0075 }, /* LATIN SMALL LETTER U */
    { 0x76, 0x0076 }, /* LATIN SMALL LETTER V */
    { 0x77, 0x0077 }, /* LATIN SMALL LETTER W */
    { 0x78, 0x0078 }, /* LATIN SMALL LETTER X */
    { 0x79, 0x0079 }, /* LATIN SMALL LETTER Y */
    { 0x7A, 0x007A }, /* LATIN SMALL LETTER Z */
    { 0x7B, 0x007B }, /* LEFT CURLY BRACKET */
    { 0x7C, 0x007C }, /* VERTICAL LINE */
    { 0x7D, 0x007D }, /* RIGHT CURLY BRACKET */
    { 0x7E, 0x007E }, /* TILDE */
    { 0x7F, 0x007F }  /* DELETE */
};

/* Latin1*/
uint16_t latin1_char_set[LATIN1_TABLE_SIZE][2] = {
    { 0x00, 0x0000 },   /* NULL */
    { 0x01, 0x0001 },   /* START OF HEADING */
    { 0x02, 0x0002 },   /* START OF TEXT */
    { 0x03, 0x0003 },   /* END OF TEXT */
    { 0x04, 0x0004 },   /* END OF TRANSMISSION */
    { 0x05, 0x0005 }, /* ENQUIRY */
    { 0x06, 0x0006 }, /* ACKNOWLEDGE */
    { 0x07, 0x0007 }, /* BELL */
    { 0x08, 0x0008 }, /* BACKSPACE */
    { 0x09, 0x0009 }, /* CHARACTER TABULATION */
    { 0x0A, 0x000A }, /* LINE FEED */
    { 0x0B, 0x000B }, /* LINE TABULATION */
    { 0x0C, 0x000C }, /* FORM FEED */
    { 0x0D, 0x000D }, /* CARRIAGE RETURN */
    { 0x0E, 0x000E }, /* SHIFT OUT */
    { 0x0F, 0x000F }, /* SHIFT IN */
    { 0x10, 0x0010 }, /* DATA LINK ESCAPE */
    { 0x11, 0x0011 }, /* DEVICE CONTROL ONE */
    { 0x12, 0x0012 }, /* DEVICE CONTROL TWO */
    { 0x13, 0x0013 }, /* DEVICE CONTROL THREE */
    { 0x14, 0x0014 }, /* DEVICE CONTROL FOUR */
    { 0x15, 0x0015 }, /* NEGATIVE ACK */
    { 0x16, 0x0016 }, /* SYNC IDLE */
    { 0x17, 0x0017 }, /* END OF TRANSMISSION */
    { 0x18, 0x0018 }, /* CANCEL */
    { 0x19, 0x0019 }, /* END OF MEDIUM */
    { 0x1A, 0x001A }, /* SUBSTITUTE */
    { 0x1B, 0x001B }, /* ESCAPE */
    { 0x1C, 0x001C }, /* INF SEP FOUR */
    { 0x1D, 0x001D }, /* INF SEP THREE */
    { 0x1E, 0x001E }, /* INF SEP TWO */
    { 0x1F, 0x001F }, /* INF SEP ONE */
    { 0x20, 0x0020 }, /* SPACE */
    { 0x21, 0x0021 }, /* EXCLAMATION MARK */
    { 0x22, 0x0022 }, /* QUOTATION MARK */
    { 0x23, 0x0023 }, /* NUMBER SIGN */
    { 0x24, 0x0024 }, /* CURRENCY SIGN */
    { 0x25, 0x0025 }, /* PERCENT SIGN */
    { 0x26, 0x0026 }, /* AMPERSAND */
    { 0x27, 0x0027 }, /* APOSTROPHE */
    { 0x28, 0x0028 }, /* LEFT PARENTHESIS */
    { 0x29, 0x0029 }, /* RIGHT PARENTHESIS */
    { 0x2A, 0x002A }, /* ASTERISK */
    { 0x2B, 0x002B }, /* PLUS SIGN */
    { 0x2C, 0x002C }, /* COMMA */
    { 0x2D, 0x002D }, /* HYPHEN-MINUS */
    { 0x2E, 0x002E }, /* FULL STOP */
    { 0x2F, 0x002F }, /* SOLIDUS */
    { 0x30, 0x0030 }, /* DIGIT ZERO */
    { 0x31, 0x0031 }, /* DIGIT ONE */
    { 0x32, 0x0032 }, /* DIGIT TWO */
    { 0x33, 0x0033 }, /* DIGIT THREE */
    { 0x34, 0x0034 }, /* DIGIT FOUR */
    { 0x35, 0x0035 }, /* DIGIT FIVE */
    { 0x36, 0x0036 }, /* DIGIT SIX */
    { 0x37, 0x0037 }, /* DIGIT SEVEN */
    { 0x38, 0x0038 }, /* DIGIT EIGHT */
    { 0x39, 0x0039 }, /* DIGIT NINE */
    { 0x3A, 0x003A }, /* COLON */
    { 0x3B, 0x003B }, /* SEMICOLON */
    { 0x3C, 0x003C }, /* LESS-THAN SIGN */
    { 0x3D, 0x003D }, /* EQUALS SIGN */
    { 0x3E, 0x003E }, /* GREATER-THAN SIGN */
    { 0x3F, 0x003F }, /* QUESTION MARK */
    { 0x40, 0x0040 }, /* COMMERCIAL AT */
    { 0x41, 0x0041 }, /* LATIN CAPITAL LETTER A */
    { 0x42, 0x0042 }, /* LATIN CAPITAL LETTER B */
    { 0x43, 0x0043 }, /* LATIN CAPITAL LETTER C */
    { 0x44, 0x0044 }, /* LATIN CAPITAL LETTER D */
    { 0x45, 0x0045 }, /* LATIN CAPITAL LETTER E */
    { 0x46, 0x0046 }, /* LATIN CAPITAL LETTER F */
    { 0x47, 0x0047 }, /* LATIN CAPITAL LETTER G */
    { 0x48, 0x0048 }, /* LATIN CAPITAL LETTER H */
    { 0x49, 0x0049 }, /* LATIN CAPITAL LETTER I */
    { 0x4A, 0x004A }, /* LATIN CAPITAL LETTER J */
    { 0x4B, 0x004B }, /* LATIN CAPITAL LETTER K */
    { 0x4C, 0x004C }, /* LATIN CAPITAL LETTER L */
    { 0x4D, 0x004D }, /* LATIN CAPITAL LETTER M */
    { 0x4E, 0x004E }, /* LATIN CAPITAL LETTER N */
    { 0x4F, 0x004F }, /* LATIN CAPITAL LETTER O */
    { 0x50, 0x0050 }, /* LATIN CAPITAL LETTER P */
    { 0x51, 0x0051 }, /* LATIN CAPITAL LETTER Q */
    { 0x52, 0x0052 }, /* LATIN CAPITAL LETTER R */
    { 0x53, 0x0053 }, /* LATIN CAPITAL LETTER S */
    { 0x54, 0x0054 }, /* LATIN CAPITAL LETTER T */
    { 0x55, 0x0055 }, /* LATIN CAPITAL LETTER U */
    { 0x56, 0x0056 }, /* LATIN CAPITAL LETTER V */
    { 0x57, 0x0057 }, /* LATIN CAPITAL LETTER W */
    { 0x58, 0x0058 }, /* LATIN CAPITAL LETTER X */
    { 0x59, 0x0059 }, /* LATIN CAPITAL LETTER Y */
    { 0x5A, 0x005A }, /* LATIN CAPITAL LETTER Z */
    { 0x5B, 0x005B }, /* LEFT SQUARE BRACKET */
    { 0x5C, 0x005C }, /* REVERSE SOLIDUS */
    { 0x5D, 0x005D }, /* RIGHT SQUARE BRACKET */
    { 0x5E, 0x005E }, /* CIRCUMFLEX ACCENT */
    { 0x5F, 0x005F }, /* LOW LINE */
    { 0x60, 0x0060 }, /* GRAVE ACCENT */
    { 0x61, 0x0061 }, /* LATIN SMALL LETTER A */
    { 0x62, 0x0062 }, /* LATIN SMALL LETTER B */
    { 0x63, 0x0063 }, /* LATIN SMALL LETTER C */
    { 0x64, 0x0064 }, /* LATIN SMALL LETTER D */
    { 0x65, 0x0065 }, /* LATIN SMALL LETTER E */
    { 0x66, 0x0066 }, /* LATIN SMALL LETTER F */
    { 0x67, 0x0067 }, /* LATIN SMALL LETTER G */
    { 0x68, 0x0068 }, /* LATIN SMALL LETTER H */
    { 0x69, 0x0069 }, /* LATIN SMALL LETTER I */
    { 0x6A, 0x006A }, /* LATIN SMALL LETTER J */
    { 0x6B, 0x006B }, /* LATIN SMALL LETTER K */
    { 0x6C, 0x006C }, /* LATIN SMALL LETTER L */
    { 0x6D, 0x006D }, /* LATIN SMALL LETTER M */
    { 0x6E, 0x006E }, /* LATIN SMALL LETTER N */
    { 0x6F, 0x006F }, /* LATIN SMALL LETTER O */
    { 0x70, 0x0070 }, /* LATIN SMALL LETTER P */
    { 0x71, 0x0071 }, /* LATIN SMALL LETTER Q */
    { 0x72, 0x0072 }, /* LATIN SMALL LETTER R */
    { 0x73, 0x0073 }, /* LATIN SMALL LETTER S */
    { 0x74, 0x0074 }, /* LATIN SMALL LETTER T */
    { 0x75, 0x0075 }, /* LATIN SMALL LETTER U */
    { 0x76, 0x0076 }, /* LATIN SMALL LETTER V */
    { 0x77, 0x0077 }, /* LATIN SMALL LETTER W */
    { 0x78, 0x0078 }, /* LATIN SMALL LETTER X */
    { 0x79, 0x0079 }, /* LATIN SMALL LETTER Y */
    { 0x7A, 0x007A }, /* LATIN SMALL LETTER Z */
    { 0x7B, 0x007B }, /* LEFT CURLY BRACKET */
    { 0x7C, 0x007C }, /* VERTICAL LINE */
    { 0x7D, 0x007D }, /* RIGHT CURLY BRACKET */
    { 0x7E, 0x007E }, /* TILDE */
    { 0x7F, 0x007F }, /* DELETE  This is #128*/
    /* The 128 first chars of latin1 are the same as ascii.
     * 128->159 are not used at all in Latin1 */
    { 0xA0, 0x00A0 }, /* NO BREAK SPACE */
    { 0xA1, 0x00A1 }, /* INVERTED EXCLAIMATION MARK */
    { 0xA2, 0x00A2 }, /* CENT */
    { 0xA3, 0x00A3 }, /* POUND */
    { 0xA4, 0x00A4 }, /* CURRENCY */
    { 0xA5, 0x00A5 }, /* YEN */
    { 0xA6, 0x00A6 }, /* BROKEN VERTICAL */
    { 0xA7, 0x00A7 }, /* SECTION */
    { 0xA8, 0x00A8 }, /* SPACING DIARESIS */
    { 0xA9, 0x00A9 }, /* COPYRIGHT */
    { 0xAA, 0x00AA }, /* FEMALE ORDINAL INDICATOR */
    { 0xAB, 0x00AB }, /* ANGLE QUOTATION MARK */
    { 0xAC, 0x00AC }, /* NEGATION */
    { 0xAD, 0x00AD }, /* SOFT HYPHEN */
    { 0xAE, 0x00AE }, /* REGISTERED TRADEMARK */
    { 0xAF, 0x00AF }, /* SPACING MACRON */
    { 0xB0, 0x00B0 }, /* DEGREE */
    { 0xB1, 0x00B1 }, /* PLUS OR MINUS */
    { 0xB2, 0x00B2 }, /* SUPERSCRIPT 2 */
    { 0xB3, 0x00B3 }, /* SUPERSCRIPT 3 */
    { 0xB4, 0x00B4 }, /* SPACING ACUTE */
    { 0xB5, 0x00B5 }, /* MICRO */
    { 0xB6, 0x00B6 }, /* PARAGRAPH */
    { 0xB7, 0x00B7 }, /* MIDDLE DOT */
    { 0xB8, 0x00B8 }, /* SPACING CEDILLA */
    { 0xB9, 0x00B9 }, /* SUPERSCRIPT 1 */
    { 0xBA, 0x00BA }, /* MASCULINE ORDINAL INDICATOR */
    { 0xBB, 0x00BB }, /* ANGLE QUOTATION MARKG (RIGHT) */
    { 0xBC, 0x00BC }, /* FRACTION 1/4 */
    { 0xBD, 0x00BD }, /* FRACTION 1/2 */
    { 0xBE, 0x00BE }, /* FRACTION 3/4 */
    { 0xBF, 0x00BF }, /* INVERTED QUESTION MARK HIGH PART BEGINS BELOW AT 192*/
    { 0xC0, 0x00C0 }, /* CAPTITAL A ACCENTED*/
    { 0xC1, 0x00C1 }, /* CAPITAL A ACCENTED */
    { 0xC2, 0x00C2 }, /* CAPITAL A ACCENTED */
    { 0xC3, 0x00C3 }, /* CAPITAL A TILDE*/
    { 0xC4, 0x00C4 }, /* CAPITAL A UMLAUT */
    { 0xC5, 0x00C5 }, /* CAPITAL A RING */
    { 0xC6, 0x00C6 }, /* CAPITAL AE*/
    { 0xC7, 0x00C7 }, /* CAPITAL C CEDILLA */
    { 0xC8, 0x00C8 }, /* CAPITAL E ACCENTED */
    { 0xC9, 0x00C9 }, /* CAPITAL E ACCENTED */
    { 0xCA, 0x00CA }, /* CAPITAL E ACCENTED */
    { 0xCB, 0x00CB }, /* CAPITAL E UMLAUT */
    { 0xCC, 0x00CC }, /* CAPITAL I ACCENTED */
    { 0xCD, 0x00CD }, /* CAPITAL I ACCENTED */
    { 0xCE, 0x00CE }, /* CAPITAL I ACCENTED */
    { 0xCF, 0x00CF }, /* CAPITAL I UMLAUT */
    { 0xD0, 0x00D0 }, /* CAPTIAL ETH*/
    { 0xD1, 0x00D1 }, /* CAPITAL N TILDE */
    { 0xD2, 0x00D2 }, /* CAPITAL O ACCENTED */
    { 0xD3, 0x00D3 }, /* CAPITAL O ACCENTED */
    { 0xD4, 0x00D4 }, /* CAPITAL O ACCENTED */
    { 0xD5, 0x00D5 }, /* CAPITAL O TILDE */
    { 0xD6, 0x00D6 }, /* CAPITAL O UMLAUT */
    { 0xD7, 0x00D7 }, /* MULTIPLICATION */
    { 0xD8, 0x00D8 }, /* CAPITAL O SLASH */
    { 0xD9, 0x00D9 }, /* CAPITAL U ACCENTED */
    { 0xDA, 0x00DA }, /* CAPITAL U ACCENTED */
    { 0xDB, 0x00DB }, /* CAPITAL U ACCENTED */
    { 0xDC, 0x00DC }, /* CAPITAL U WITH UMLAUT */
    { 0xDD, 0x00DD }, /* CAPITAL Y WITH ACUTE */
    { 0xDE, 0x00DE }, /* CAPITAL THORN */
    { 0xDF, 0x00DF }, /* SMALL SHARP S */
    { 0xE0, 0x00E0 }, /* SMALL A WITH GRAVE*/
    { 0xE1, 0x00E1 }, /* SMALL A WITH ACUTE */
    { 0xE2, 0x00E2 }, /* SMALL A WITH CIRCUMFLEX */
    { 0xE3, 0x00E3 }, /* SMALL A TILDE */
    { 0xE4, 0x00E4 }, /* SMALL A UMLAUT */
    { 0xE5, 0x00E5 }, /* SMALL A RING */
    { 0xE6, 0x00E6 }, /* SMALL AE */
    { 0xE7, 0x00E7 }, /* SMALL C CEDILLA */
    { 0xE8, 0x00E8 }, /* SMALL E WITH GRAVE */
    { 0xE9, 0x00E9 }, /* SMALL E WITH ACUTE */
    { 0xEA, 0x00EA }, /* SMALL E WITH CIRCUMFLEX */
    { 0xEB, 0x00EB }, /* SMALL E WITH UMLAUT */
    { 0xEC, 0x00EC }, /* SMALL I WITH GRAVE */
    { 0xED, 0x00ED }, /* SMALL I WITH ACUTE */
    { 0xEE, 0x00EE }, /* SMALL I WITH CUIRCUMFLEX */
    { 0xEF, 0x00EF }, /* SMALL I WITH UMLAUT */
    { 0xF0, 0x00F0 }, /* SMALL ETH */
    { 0xF1, 0x00F1 }, /* SMALL N TILDE */
    { 0xF2, 0x00F2 }, /* SMALL O WITH GRAVE */
    { 0xF3, 0x00F3 }, /* SMALL O WITH ACUTE */
    { 0xF4, 0x00F4 }, /* SMALL O WITH CIRCUMFLEX */
    { 0xF5, 0x00F5 }, /* SMALL O WITH TILDE */
    { 0xF6, 0x00F6 }, /* SMALL O WITH UMLAUT */
    { 0xF7, 0x00F7 }, /* DIVISION */
    { 0xF8, 0x00F8 }, /* SMALL O SLASH */
    { 0xF9, 0x00F9 }, /* SMALL U WITH GRAVE */
    { 0xFA, 0x00FA }, /* SMALL U WITH ACUTE */
    { 0xFB, 0x00FB }, /* SMALL U CIRCUMFLEX */
    { 0xFC, 0x00FC }, /* SMALL U UMLAUT */
    { 0xFD, 0x00FD }, /* SMALL Y ACUTE */
    { 0xFE, 0x00FE }, /* SMALL THORN */
    { 0xFF, 0x00FF }  /* SMALL Y WITH UMLAUT */
};



/**
  * All combos below requires a base septet for the UDH.
  */
int UDH_BASE_COST_SEPTETS = 1;

/**
 * Using a shift table requires 4 septets + length.
 */
//
int UDH_COST_SINGLE_SHIFT_TABLE_SEPTETS = 4;

/**
 * Applying both locking table and shift table requires 7 septets + base.
 */
int UDH_COST_TWO_SHIFT_TABLES_SEPTETS = 7;

/**
 * Multipart message require 6 septets plus base
 */
int UDH_COST_CONCATENATED_MESSAGE_SEPTETS = 6;

/**
 * Multipart message using a byte aligned encoding will need:
 * (UDH_BASE_COST_SEPTETS + UDH_COST_CONCATENATED_MESSAGE_SEPTETS) * 7 = 49 bits => 7 bytes
 */
int UDH_COST_CONCATENATED_MESSAGE_OCTETS = 7;

/**
 * Multipart message using a 2 byte aligned encoding will need:
 * (UDH_BASE_COST_SEPTETS + UDH_COST_CONCATENATED_MESSAGE_SEPTETS) * 7 = 49 bits => 7 bytes
 * However since we have an even 140 bytes to play with using 140-7=133 bytes does not make
 * any sense since we need an even amount of bytes for each letter.
 * This is complex to solve in the calculation. It is much simpler to add the restriction
 * here and we get it for free when calculating how many chars we have left for UCS2.
 */
int UDH_COST_CONCATENATED_MESSAGE_WORD = 4;

#endif


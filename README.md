# sms charset analyzer
Standalone ansi-c implementation to detect the optimal charset for sms encoding

Pass any UTF-16 encoded string buffer and the code will output:
- The most optimal sms encoder for this message.
- Number of sms messages needed to send it.
- Characters left in the current fragment.

Supported encodings are:
- GSM7
- GSM7-ES
- HP-ROMAN8
- ASCII
- LATIN1
- UCS2


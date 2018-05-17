#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


#define BCD1 8

void writeDigit( int bcd )
{
  int i;
  printf("\nInput bcd = %d\n", bcd);
  printf("In binary: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(bcd));
  printf("\n");

  for( i = 0; i < 4; i++ ) {
    int bcdred = bcd & 0x01;
    printf("\nPIN: %d, value: %o\n", BCD1 + i, bcdred);
    printf("After & 0x01 in binary: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(bcdred));
    printf("\n");
    bcd = bcd >> 1;
    printf("After >> in binary: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(bcd));
    printf("\n");
  }
}

int main()
{
  int bcd;
  for( bcd = 0; bcd <= 11; bcd++ ) {
    writeDigit( bcd );
  }

  return 0;
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pdu.h"

char string[] = "How are you?";

void print_bin_byte(int x) {
  int n;
  for(n = 0; n < 8; n++) {
    if((x & 0x80) !=0) {
      printf("1");
    } else {
      printf("0");
    }
    if (n==3) {
      printf(" "); /* insert a space between nybbles */
    }
    x <<= 1;
  }
  printf("\n");
}


int main(void) {
  int len = strlen(string);
  int i;

  for (i = 0; i < len; i++) {
    printf("(%i) %i : %c - ", (i % 8), string[i], string[i]);
    print_bin_byte(string[i]);
  }

  // smsd.c:  make_pdu(to,text,textlen,alphabet,flash,report,with_udh,udh_data,DEVICE.mode,pdu,validity, replace_msg, system_msg, to_type);

  char* message = "teretoretoretere";
  char* to = "3725215471";
  int alphabet = 0;
  int flash = 0;
  int with_udh = 0;
  char* udh_data = "";
  char* mode = "new";
  int report = 0;
  char pdu[1024] = {};
  int validity = 0;
  int system_msg = 0;
  int replace_msg = 0;
  int to_type = 1;

  make_pdu(to, message, strlen(message), alphabet, flash, report, with_udh, udh_data, mode, pdu, validity, replace_msg, system_msg, to_type);

  printf("PDU:\n\n%s\n\n", pdu);

  return 0;
}

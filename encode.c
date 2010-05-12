#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pdu.h"

int main(void) {
  // smsd.c:  make_pdu(to,text,textlen,alphabet,flash,report,with_udh,udh_data,DEVICE.mode,pdu,validity, replace_msg, system_msg, to_type);

  // char* message = "www.knivesandengraving.com";
  char* message = "viltsik";
  char* to = "3725215471";
  int alphabet = 1;
  int flash = 0;
  int with_udh = 0;
  char* udh_data = "";
  char* mode = "new";
  int report = 0;
  char pdu[1024] = {};
  int validity = 167; // 1 day
  int system_msg = 0;
  int replace_msg = 0;
  int to_type = 1;

  make_pdu(to, message, strlen(message), alphabet, flash, report, with_udh, udh_data, mode, pdu, validity, replace_msg, system_msg, to_type);

  printf("\nPDU: %s\n\n", pdu);

  return 0;
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char string[] = "hellohello";

void bin_prnt_byte(int x) {
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
    bin_prnt_byte(string[i]);
  }

  return 0;
}

#include "UPASS.h"


char *cipher(char str[])
{
  int len = strlen(str);
  char a;
  int i, m;
  char cipher[3*MAX_PASSWORD_LENGTH];

  for (i=0, m=0; i<len; i++, m++)
  {
    int x, y, z;
    a = str[i];

    /*
    The 0, 4 and 2 in the three lines below can each be altered to any integer
    to create a key. The key must however stay constant so that the cipher
    remains constant and encrypted strings can be compared.
    */
    #ifdef DEBUG
    printf("Before cipher: %c\n", a);
    #endif
    x = ((((int)a + 0)% 93) + 33);
    y = ((((int)a + 4)% 93) + 33);
    z = ((((int)a + 2)% 93) + 33);



    cipher[m] = (char)x;
    #ifdef DEBUG
    printf("After cipher: %c\n", cipher[m]);
    #endif
    m++;
    cipher[m] = (char)y;
    #ifdef DEBUG
    printf("After cipher: %c\n", cipher[m]);
    #endif
    m++;
    cipher[m] = (char)z;
    #ifdef DEBUG
    printf("After cipher: %c\n", cipher[m]);
    #endif
  }
  cipher[m] = '\0';

  char* cipherPointer = cipher;
  char* returnPointer = malloc(len+1);
  char* temp;
  temp = returnPointer;
  while(*cipherPointer){
    *temp++ = *cipherPointer++;
  }
    #ifdef DEBUG
    printf("String to be returned from cipher: %s\n", returnPointer);
    #endif
  return returnPointer;
}
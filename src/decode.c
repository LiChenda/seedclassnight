//
// Created by leo on 6/10/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/ReadBmp.h"
#include "../include/decode.h"


char message[500];

void decode(char *filename)
{
  int length = 0;
  u_8 tmp;
  char  tmpc;
  ImageData img = readBitMap(filename);
  int i, j;
  for (i = 0; i < 8; ++i) {
    tmp = img.pixelHead[i].Red;
    length = length << 1;
    length += tmp & 1;
  }
  /*printf("length: %d\n", length);*/
  for (j = 0; j < length; j++) {
    tmpc = 0;
    for (i = 0; i < 8; ++i) {
      tmp = img.pixelHead[8 + j * 8 + i].Red;
      /*printf("%u\n", tmp);*/
      tmpc = tmpc << 1;
      tmpc += tmp & 1;
    }
    /*printf(" \n");*/
    message[j] = tmpc;
  }
  message[length] = '\0';


  free(img.pixelHead);
}


int main(int argc, char *argv[])
{
  int i;
  for (i = 1; i < argc; ++i) {
    decode(argv[i]);
    printf("%s\n", message);
  }
  return 0;
}



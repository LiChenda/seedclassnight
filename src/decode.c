//
// Created by leo on 6/10/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/ReadBmp.h"
#include "../include/decode.h"


char message[MAXLEN];

void decode(char *filename)
{
  int length = 0;
  u_8 tmp;
  char  tmpc;
  ImageData img = readBitMap(filename);

  u_8 *byteHead = (u_8*)img.pixelHead;

  int i, j;
  for (i = 0; i < 8; ++i) {
    tmp = byteHead[i];
    length = length << 2;
    length += tmp & 3;
  }
  printf("length: %d\n", length);
  for (j = 0; j < length; j++) {
    tmpc = 0;
    for (i = 0; i < 8; ++i) {

      /*tmp = img.pixelHead[8 + j * 8 + i].Red;*/
      tmp = byteHead[8 + j * 8 + i];
      /*printf("%u\n", tmp);*/
      tmpc = tmpc << 1;
      tmpc += tmp & 1;

    }
    /*printf(" \n");*/
    message[j] = tmpc;
  }
  message[length] = '\0';

  /*for (i = 120; i < 400; ++i) {*/

    /*if(img.pixelHead[i].Red != 237 )*/
    /*{*/
      /*printf("%d\n",i );*/
    /*}*/

  /*}*/

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



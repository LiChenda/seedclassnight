/*=============================================================================
#     FileName: decode.c
#         Desc: decode message from bit map file
#       Author: LiChenda
#        Email: lichenda1996@gmail.com
#     HomePage: https://github.com/LiChenda
#      Version: 0.0.1
#   LastChange: 2016-06-10 18:27:21
#      History:
=============================================================================*/

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

  /*read bmp file */
  ImageData img = readBitMap(filename);

  u_8 *byteHead = (u_8*)img.pixelHead;

  /*get message length*/
  int i, j;
  for (i = 0; i < 8; ++i) {
    tmp = byteHead[i];
    length = length << 2;
    length += tmp & 3;
  }
  //printf("length: %d\n", length);
  
  /*decode message */
  for (j = 0; j < length; j++) {
    tmpc = 0;
    for (i = 0; i < 8; ++i) {
      tmp = byteHead[8 + j * 8 + i];
      tmpc = tmpc << 1;
      tmpc += tmp & 1;
    }
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



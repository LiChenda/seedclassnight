/*=============================================================================
#     FileName: encrypt.c
#         Desc: encrypt message into bit map file 
#       Author: LiChenda
#        Email: lichenda1996@gmail.com
#     HomePage: https://github.com/LiChenda
#      Version: 0.0.1
#   LastChange: 2016-06-10 23:26:40
#      History:
=============================================================================*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/encrypt.h"
#include "../include/ReadBmp.h"


void encrypt(char *filename, char* message)
{
  /*get message length*/
  u_16 len = (u_16)strlen(message);

  /*read bit map*/
  ImageData imageData = readBitMap(filename);
  u_8 *byteHead = (u_8*)imageData.pixelHead;

  int i, j;
  /*encrypt message length*/
  for (i = 0; i < 8; ++i) {
    u_8 testbyte =((u_8)3) & (len >> (14 - 2*i)); //bits to put
    byteHead[i] =
      (byteHead[i] & ((u_8)252)) //set last 2 bits 0
      + testbyte;
  }

  /*encrypt message into pixels*/
  for (j = 0; j < len; ++j) {
    for ( i = 0; i < 8; ++i) {
      u_8 testbyte =((u_8)1) & (message[j] >> (7 - i)); //bit to put
      byteHead[8 + j * 8 + i] =
        (byteHead[8 + j * 8 + i] & ((u_8)254)) //set last bit 0
        + testbyte;
    }
  }

  /*get original file*/
  FILE *filePtr = fopen(filename, "rb");
  u_8 *file = (u_8 *)malloc(imageData.fileSize);
  fread(file, imageData.fileSize, 1, filePtr);
  fclose(filePtr);

  /*modify and write back*/
  memcpy(file + imageData.offset, imageData.pixelHead, imageData.datasize);
  char *output = "output.bmp";
  filePtr = fopen(output, "wb");
  fwrite(file, imageData.fileSize, 1, filePtr);
  fclose(filePtr);

  free(file);
  free(imageData.pixelHead);
}

int main(int argc, char *argv[])
{
  char message[MAXLEN]; 
  int i = 0;
  while (1) {
    message[i] = getchar();
    if (message[i] == EOF) {
      message[i] = '\0';
      break; 
    }
    i++;
  }

  encrypt(argv[1], message);
  return 0;
}

/*=============================================================================
#     FileName: encrypt.c
#         Desc: 
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
  u_8 len = (u_8)strlen(message);
  /*printf("input len %u\n", len);*/
  ImageData imageData = readBitMap(filename);
  int i, j;
  for (i = 0; i < 8; ++i) {
    u_8 testbyte =((u_8)1) & (len >> (7-i));
    /*printf("%u\n", testbyte);*/
    imageData.pixelHead[i].Red =
      (imageData.pixelHead[i].Red & ((u_8)254))
      + testbyte;
    /*printf("%u\n", imageData.pixelHead[i].Red);*/
  }
  printf("\n");
  for (j = 0; j < len; ++j) {
    for ( i = 0; i < 8; ++i) {
      u_8 testbyte =((u_8)1) & (message[j] >> (7-i));
      imageData.pixelHead[8 + j * 8 + i].Red =
        (imageData.pixelHead[8 + j * 8 + i].Red & ((u_8)254))
        + testbyte;
      /*printf("%u\n", imageData.pixelHead[8 + j * 8 + i].Red);*/
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
  char message[500]; 
  scanf("%s", message);
  encrypt(argv[1], message);
  return 0;
}

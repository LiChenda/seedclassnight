/*=============================================================================
#     FileName: ReadBmp.c
#         Desc: 
#       Author: LiChenda
#        Email: lichenda1996@gmail.com
#     HomePage: https://github.com/LiChenda
#      Version: 0.0.1
#   LastChange: 2016-06-10 23:26:06
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "../include/ReadBmp.h"



ImageData readBitMap(char *filename)
{
  FILE *filePtr;
  ImageData imageData;
  imageData.pixelHead = NULL;

  /*open as binary file*/
  filePtr = fopen(filename, "rb");
  if (filePtr == NULL) {
    printf("file open failed!\n");
    return imageData; 
  }

  u_16 identfy;
  u_32 filesize;
  u_32 reversed;
  u_32 dataoffset;
  /** attention:
  * here is a problem
   * sizeof(fileHeader) should be 14 but turn out to be 16
   */
  //fread(&fileHeader, sizeof(fileHeader), 1, filePtr);
  /* read file header*/
  fread(&identfy, 2, 1, filePtr);
  fread(&filesize, 4, 1, filePtr);
  fread(&reversed, 4, 1, filePtr);
  fread(&dataoffset, 4, 1, filePtr);
  fileHeader.identdy = identfy;
  fileHeader.fileSize = filesize;
  fileHeader.reserved = reversed;
  fileHeader.dataOffset = dataoffset;

  /*test bit map*/
  if(fileHeader.identdy != 0x4D42)
  {
    printf("identdy false %x\n", fileHeader.identdy);
    fclose(filePtr);
    return imageData;
  }
  fread(&infoHeader, sizeof(infoHeader), 1, filePtr);

  if(infoHeader.colorByte != 0x18)
  {
    printf("not a 24 bit true color image\n");
    return imageData;
  }

  imageData.pixelHead = (Pixel*)malloc(infoHeader.dataSize);
  imageData.datasize = infoHeader.dataSize;
  imageData.fileSize = fileHeader.fileSize;
  imageData.offset = fileHeader.dataOffset;

  fseek(filePtr, fileHeader.dataOffset , SEEK_SET);
  if(!imageData.pixelHead)
  {
    free(imageData.pixelHead);
    fclose(filePtr);
    printf("memory alloc failed\n");
    return imageData;
  }
  fread(imageData.pixelHead, infoHeader.dataSize, 1,filePtr);
  fclose(filePtr);
  return imageData;

}


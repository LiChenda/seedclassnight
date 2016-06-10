//
// Created by leo on 6/10/16.
//

#ifndef S_NIGHT_TYPES_H
#define S_NIGHT_TYPES_H

typedef unsigned char u_8;
typedef unsigned short u_16;
typedef unsigned int u_32;
typedef unsigned long u_64;

typedef const unsigned char cu_8;
typedef const unsigned short cu_16;
typedef const unsigned int cu_32;
typedef const unsigned long cu_64;

typedef signed char s_8;
typedef signed short s_16;
typedef signed int s_32;
typedef signed long s_64;

#define False (0)
#define True (1)


typedef struct _Pixel {
  /* data */
  u_8 Blue;
  u_8 Green;
  u_8 Red;
} Pixel;

typedef struct _FileHeader {
  /* data */
  u_16 identdy;
  u_32 fileSize;
  u_32 reserved;
  u_32 dataOffset;
} FileHeader;

typedef struct _InfoHeader {
  /* data */
  u_32 infoHeaderSize;
  u_32 imageWidth;
  u_32 imageHight;
  u_16 plane;
  u_16 colorByte;
  u_32 compressType;
  u_32 dataSize;
  u_32 pixelPerMeterH;
  u_32 pixelPerMeterV;
  u_32 colorNum;
  u_32 importantColorNum;
} InfoHeader;

typedef struct _imagData {
  Pixel *pixelHead;
  u_32 datasize;
  u_32 fileSize;
  u_32 offset;
  u_32 imageWidth;
  u_32 imageHight;
} ImageData;







#endif //S_NIGHT_TYPES_H

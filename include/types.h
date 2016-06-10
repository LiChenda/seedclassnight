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
#define MAXLEN 5000


typedef struct _Pixel {
  /* data */
  u_8 Blue;
  u_8 Green;
  u_8 Red;
} Pixel;

typedef struct _FileHeader {
  u_16 identdy; //文件标志
  u_32 fileSize;//文件大小
  u_32 reserved;//保留字
  u_32 dataOffset;//阵列区偏移量
} FileHeader;

typedef struct _InfoHeader {
  u_32 infoHeaderSize;  //信息头大小
  u_32 imageWidth;      //图片宽度
  u_32 imageHight;      //图片高度
  u_16 plane;           //位面数
  u_16 colorByte;       //像素点位数 24位位图为18H
  u_32 compressType;    //压缩信息
  u_32 dataSize;        //阵列区的大小
  u_32 pixelPerMeterH;  //水平分辨率
  u_32 pixelPerMeterV;  //垂直分辨率
  u_32 colorNum;        //颜色数
  u_32 importantColorNum;//重要颜色数
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

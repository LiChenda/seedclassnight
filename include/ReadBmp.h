/*=============================================================================
#     FileName: ReadBmp.h
#         Desc: Read bit map file
#       Author: LiChenda
#        Email: lichenda1996@gmail.com
#     HomePage: https://github.com/LiChenda
#      Version: 0.0.1
#   LastChange: 2016-06-10 18:33:39
#      History:
=============================================================================*/

#ifndef S_NIGHT_READBMP_H
#define S_NIGHT_READBMP_H
#include "../include/types.h"

FileHeader fileHeader;
InfoHeader infoHeader;


ImageData readBitMap(char *filename);

#endif //S_NIGHT_READBMP_H_H

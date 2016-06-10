//
// Created by leo on 6/10/16.
//

#ifndef S_NIGHT_READBMP_H
#define S_NIGHT_READBMP_H
#include "../include/types.h"

FileHeader fileHeader;
InfoHeader infoHeader;


ImageData readBitMap(char *filename);

#endif //S_NIGHT_READBMP_H_H

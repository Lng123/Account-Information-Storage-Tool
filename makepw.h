#include <stdio.h>
#define ISIZE 50

#ifndef MAKEPW_H
#define MAKEPW_H

int get_valid_int(const char prompt[], int eof,int min, int max);
int get_int(const char prompt[], int eof);
void makepw(int length);

#endif

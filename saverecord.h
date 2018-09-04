#include <stdio.h>
#include "struct.h"


#ifndef SAVERECORD_H
#define SAVERECORD_H

int saverecordmain();

int enter_record(const char *prompt1, const char *prompt2, const char *prompt3, account *prec);

int store_record(const account *prec, int count);


#endif

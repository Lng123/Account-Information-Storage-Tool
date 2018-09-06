#include <stdio.h>
#include "struct.h"


#ifndef ARRANGERECORD_H
#define ARRANGERECORD_H

int findmain();

int validateSite(char *arr);

char* findUser(char *fname, char *username);

void removeSpaces(account *prec);

void removeSpacesHelper(char *ptr);

int checkPwd(char* pwd, char* inputPwd);
#endif

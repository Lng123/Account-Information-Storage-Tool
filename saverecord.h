#include <stdio.h>
#define ISIZE 50
#define NSIZE 25

#ifndef SAVERECORD_H
#define SAVERECORD_H

typedef struct {
    char username[NSIZE];
    char password[NSIZE];
    char site[ISIZE];
}account;

int enter_record(const char *prompt1, const char *prompt2, const char *prompt3, account *prec);

int store_record(const account *prec);

#endif

#include <stdio.h>
#define ISIZE 50

#ifndef SAVERECORD_H
#define SAVERECORD_H

typedef struct {
    char username[ISIZE];
    char password[ISIZE];
    char site[ISIZE];
}password;

int enter_record(const char *prompt1, const char *prompt2, const char *prompt3);

#endif

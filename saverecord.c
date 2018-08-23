#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "saverecord.h"
#define BUFSIZE 256
#define ISIZE 50
#define NSIZE 25


int main(void) {
    account *record = malloc(sizeof(account));
    enter_record("Enter the website\n", "Enter the username\n", "Enter the password\n", record);
    store_record(record);
    free(record);

    return 0;
}

int enter_record(const char *prompt1, const char *prompt2, const char *prompt3, account *prec) {
    char line[BUFSIZE];
    char site[ISIZE];
    char username[NSIZE];
    char password[NSIZE];

    printf("%s", prompt1);
    while(1) {
        if (!fgets(line, BUFSIZE, stdin)) {
            clearerr(stdin);
            return 0;
        }
        if(sscanf(line, "%[^\n]s", site) != 1) {
            clearerr(stdin);
            printf("Invalid. %s\n", prompt1);
        } else {
            printf("%s", prompt2);
            while(1) {
                if (!fgets(line, BUFSIZE, stdin)) {
                    clearerr(stdin);
                    return 0;
                }
                if(sscanf(line, "%s", username) != 1) {
                    clearerr(stdin);
                    printf("Invalid. %s\n", prompt1);
                } else {
                    printf("%s", prompt3);
                    while(1) {
                        if (!fgets(line, BUFSIZE, stdin)) {
                            clearerr(stdin);
                            return 0;
                        }
                        if(sscanf(line, "%s", password) != 1) {
                            clearerr(stdin);
                            printf("Invalid. %s\n", prompt1);
                        } else {
                            /*Enter encrypt function right here.
                            And then store it into the struct*/
                            strcpy(prec->username, username);
                            strcpy(prec->password, password);
                            strcpy(prec->site, site);

                            printf("%s %s %s", site, username, password);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

/*Print function to print the struct into the file here*/
int store_record(const account *prec) {
    FILE *fp;

    if ((fp = fopen("passwords.txt", "a+")) == 0) {
        perror("fopen");
        return 1;
    }

    fprintf(fp, "%50s %25s %25s ", prec->site, prec->username, prec->password);

    if (fclose(fp) != 0) {
        perror("fclose");
        return 2;
    }

    return 0;
}


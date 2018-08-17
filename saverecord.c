#include <stdio.h>
#include "saverecord.h"
#define BUFSIZE 256
#define ISIZE 50



int enter_record(const char *prompt1, const char *prompt2, const char *prompt3) {
    char line[BUFSIZE];
    char site[ISIZE];
    char username[ISIZE];
    char password[ISIZE];

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
/*
int main(void) {
    enter_record("Enter the website\n", "Enter the username\n", "Enter the password\n");

    return 0;
}
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arrangerecord.h"
#include "saverecord.h"

#define SITENAME_LENGTH 30
#define CREDENTIAL_LENGTH 20


int saverecordmain(void) {
	/*commented out*/
	/*char line[BUFSIZE];
	char fname[SITENAME_LENGTH], username[CREDENTIAL_LENGTH], inputPwd[CREDENTIAL_LENGTH];
	char *pwd;*/

    account *record = malloc(sizeof(account));
	
	/*4 inputs - three strings for display and the save the file(used malloc)*/
	/*save the each inputs in the order*/
	while( enter_record("Enter the website\n", "Enter the username\n", "Enter the password\n", record) != 0 ) {
		
		removeSpaces(record);
		store_record(record, 0);
	}
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
		/*grab the fist site -1*/
        if (!fgets(line, BUFSIZE, stdin)) {
            clearerr(stdin);
            return 0;
        }
		/*store the site*/
        if(sscanf(line, "%[^\n]s", site) != 1) {
clearerr(stdin);
printf("Invalid. %s\n", prompt1);
		}
		if (site[0] == '@') {
			return 0;
		}
		if (validateSite(site) != 1) {
			continue;
		}
		else {
			printf("%s", prompt2);
			while (1) {
				if (!fgets(line, BUFSIZE, stdin)) {
					clearerr(stdin);
					return 0;
				}


				if (sscanf(line, "%s", username) != 1) {
					clearerr(stdin);
					printf("Invalid. %s\n", prompt1);
				}

				if (username[0] == '@') {
					return 0;
				}

				else {
					printf("%s", prompt3);
					while (1) {
						if (!fgets(line, BUFSIZE, stdin)) {
							clearerr(stdin);
							return 0;
						}
						if (sscanf(line, "%s", password) != 1) {
							clearerr(stdin);
							printf("Invalid. %s\n", prompt1);
						}
						if (password[0] == '@') {
							return 0;
						}
						else {
							/*Enter encrypt function right here.
							And then store it into the struct*/
							strcpy(prec->username, username);
							strcpy(prec->password, password);
							strcpy(prec->site, site);

							printf("%s %s %s \n", site, username, password);
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

/*Print function to print the struct into the file here*/
int store_record(const account *prec, int count) {
	FILE *fp;
	/*changed to save the folder by the site name*/
	if ((fp = fopen(prec->site, "a+")) == 0) {
		perror("fopen");
		return 1;
	}

	/*print out the file name*/
	fprintf(fp, "%s %s %d\n", prec->username, prec->password, ++count);

	if (fclose(fp) != 0) {
		perror("fclose");
		return 2;
	}

	return 0;
}


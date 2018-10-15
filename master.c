#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "masterlogin.h"
#define SITENAME_LENGTH 30
#define CREDENTIAL_LENGTH 20

/*please save your master password on your master.txt*/
int mastermain() {
	size_t i;
	char line[BUFSIZE] = { 0 }, line2[BUFSIZE] = { 0 };
	char password[NSIZE] = { 0 };
	char pwd[NSIZE] = { 0 };
	FILE *fp = fopen("master1.txt", "r+");
	if (fp == 0) {
		printf("fail to open\n");
	}
	/*printf("[%s] [%s]", password, pwd);*/
	printf("Enter your master password\n");
	if (!fgets(line, BUFSIZE, stdin)) {
		clearerr(stdin);
		return 0;
	}


	if (sscanf(line, "%s", password) != 1) {
		clearerr(stdin);
		printf("Invalid. %s\n", line);
        printf("[%s] [%s]", password, pwd);
	}


	while (fgets(line2, BUFSIZE, fp)) {
		printf("[%s] [%s]\n", password, line2);
		for (i = 0; password[i] != '\0'; i++) {
			if (password[i] != line2[i]) {
				printf("your master password is incorrect");
				fclose(fp);
				return 0;
			}
		}
		if (line2[i] != '\0') {
			fclose(fp);
			return 0;
		}
	}
	fclose(fp);
	printf("your master password is correct\n");
	return 1;		
}
#include <stdio.h>
#include "struct.h"


#ifndef MASTER_H
#define MASTER_H
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
	printf("enter your master password\n");
	if (!fgets(line, BUFSIZE, stdin)) {
		clearerr(stdin);
		return 0;
	}


	if (sscanf(line, "%s", password) != 1) {
		clearerr(stdin);
		printf("Invalid. %s\n", line);
	}
	printf("[%s] [%s]", password, pwd);


	while (fgets(line2, BUFSIZE, fp)) {
		printf("[%s] [%s]", password, line2);
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


#endif
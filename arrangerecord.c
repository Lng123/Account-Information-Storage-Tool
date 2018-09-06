#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arrangerecord.h"

#define SITENAME_LENGTH 30
#define CREDENTIAL_LENGTH 20



int findmain(void) {
	char line[BUFSIZE];
	char fname[SITENAME_LENGTH], username[CREDENTIAL_LENGTH], inputPwd[CREDENTIAL_LENGTH];
	char *pwd;

	/*account *record = malloc(sizeof(account));*/


	/* this is the section to find the pass through inputing the site name, username, and the password
	if you put the wrong one, it will provide you right one*/
	while (1) {
		/*instruction*/
		printf("please put the main site name without www. and .com\n");
		/*grab and scan to check for filename*/
		if (fgets(line, BUFSIZE, stdin)) {
			if (sscanf(line, "%s", fname) != 1) {
				clearerr(stdin);
				printf("Invalid\n please put the main site name without www. and .com");
				continue;
			}

		}
		/*grab and scan to check for filename*/
		printf("please input your username:\n");
		if (fgets(line, BUFSIZE, stdin)) {
			if (sscanf(line, "%s", username) != 1) {
				clearerr(stdin);
				printf("Invalid\n please put the main site name without www. and .com");
			}


		}
		printf("please input your pwd:\n");
		if (fgets(line, BUFSIZE, stdin)) {
			sscanf(line, "%s", inputPwd);
		}

		pwd = findUser(fname, username);
		if (pwd != 0) {
			if (checkPwd(pwd, inputPwd) == 1) {
				printf("%s == %s\n", pwd, inputPwd);
				free(pwd);
				break;
			}
			else {
				printf("pwd is incorrect. Try again.\n");
				free(pwd);

			}


		}
	}




	return 0;
}

/*
*check the valid websites if names does not match it will not work
* return int 1:valid 0:invalid
*/
int validateSite(char *arr) {

	size_t i, j;
	/* row[0] - google, row[1] - yahoo*/
	char sites[2][10] = { "google" , "yahoo" };
	printf("testing [%s] [%s]\n", sites[0], sites[1]);

	for (i = 0; i < 2; i++) {
		for (j = 0; arr[j] != '\0'; j++) {
			printf("%c %c\n", arr[j], sites[i][j]);
			/*if they do nt math return and redo*/
			if (arr[j] != sites[i][j]) {
				break;
			}
		}
		/*if they do it will break*/
		if (sites[i][j] == '\0') {
			return 1;
		}
	}
	return 0;

}

/* the fucntion to find the user name
*	the first input file name and it will open the name
*	the second input username is required to opent then folder
*/
char* findUser(char *fname, char *username) {

	size_t i, j;
	FILE* fp;
	char line[BUFSIZE];
	char *ptrPwd;
	if ((fp = fopen(fname, "r+")) == 0) {
		perror("fopen");
		return 0;
	}

	while (fgets(line, BUFSIZE, fp)) {
		for (i = 0; username[i] != '\0'; i++) {
			if (username[i] != line[i]) {
				break;
			}
		}
		/*this is to handle unmatched parts and to continue to
		*search the rest of the words that are related to
		*and display them*/
		if (line[i] != ' ') {
			continue;
		}
		ptrPwd = malloc(CREDENTIAL_LENGTH);

		/* loop through to find the end of the password and put '\0' there*/
		for (j = 0; line[j + i + 1] != '\0'; j++) {
			if (line[j + i + 1] == ' ') {
				ptrPwd[j] = '\0';
				break;
			}
			else {
				ptrPwd[j] = line[j + i + 1];
			}
		}
		return ptrPwd;
	}
	return 0;
}


/*this is the remove the unnessary spaces that is made in the saving file*/
void removeSpaces(account *prec) {
	removeSpacesHelper(prec->password);
	removeSpacesHelper(prec->site);
	removeSpacesHelper(prec->username);
}
/*helper function which is to trim off the all spaces*/
void removeSpacesHelper(char *ptr)
{
	/*To keep track of non-space character count*/
	int count = 0;
	size_t i;
	/* Traverse the given string. If current character
	is not space, then place it at index 'count++'*/
	for (i = 0; ptr[i] != '\0'; i++)
		if (ptr[i] != ' ')
			ptr[count++] = ptr[i]; /* here count is
								   incremented*/
	ptr[count] = '\0';
}

/*check the passsword wheather it is correct or not
* if they do not match they will print the password
*/
int checkPwd(char* pwd, char* inputPwd) {
	size_t i = 0;
	/*travere and check between input and the actual password*/
	for (; pwd[i] != '\0' && inputPwd[i] != '\0'; i++) {
		if (pwd[i] != inputPwd[i]) {
			return 0;
		}
	}
	if (pwd[i] != '\0' || inputPwd[i] != '\0') {
		return 0;
	}
	return 1;
}
#include <stdio.h> 
#include <ctype.h> 
#include <string.h>
#include <stdlib.h>
#include "saverecord.h"
#define BUFSIZE 256
#define ISIZE 50




int menu(const char *choices[], const char *prompt);
int main(void) {
    account *record = malloc(sizeof(account));

    int choice;
    const char *choices[] = { "Save a password", "Find a password", "Password Generator","Quit", 0};
    choice = menu(choices, "> Enter your choice");
    switch(choice) {
        case 1:
            enter_record("Enter the website\n", "Enter the username\n", "Enter the password\n", record);
            free(record);
            break;
        case 2:
            printf("%d", choice);
            break;
        case 3:
            printf("%d", choice);
            break;
    }

    return 0;
}


int menu(const char *choices[], const char *prompt){
  char line[BUFSIZE];
  int n;
  while(1){  
    size_t i;
    for(i=0;choices[i]!=0;i++){
        printf("%ld : %s\n",i+1,choices[i]);
    }
    printf("%s\n", prompt);
    if(!fgets(line, BUFSIZE,stdin)){
        clearerr(stdin);
        fprintf(stderr,"No Input\n");
        return 0;
    } 
    if(sscanf(line, " %d", &n)==1 && n>0 && n <=(int)i)
        return n;       
  }
  return 0;
}

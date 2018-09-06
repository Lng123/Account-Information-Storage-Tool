#include <stdio.h> 
#include <ctype.h> 
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include "arrangerecord.h"
#include "saverecord.h"
#include "masterlogin.h"
#include "makepw.h" 
#define BUFSIZE 256
#define ISIZE 50




int menu(const char *choices[], const char *prompt);
int main(void) {

    int choice;
    int length;
    char pass[BUFSIZE];
    

	
    const char *choices[] = { "Save a password", "Find a password", "Password Generator","Quit", 0};
    choice = menu(choices, "> Enter your choice");
	
	srand(time(0));
	mastermain();
    switch(choice) {
        case 1:
			saverecordmain(); 
            break;
        case 2:
			findmain();
            break;
        case 3:
            length = get_valid_int("Enter a Password Length",0,5,55);
            makepw(length, pass);
            printf("\n%s",pass);
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

#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include "makepw.h" 
#define BUFSIZE 256
#define ISIZE 50
#define LINESIZE 256
int menupw(const char *choices[], const char *prompt);
void makepw(int length);
int mode(int num);
int get_int(const char prompt[], int eof);
int get_valid_int(const char prompt[], int eof,int min, int max);



/* number,caps,specialcharacters*/
void makepw(int length) {
    
    int i;
    int test;
    int test2;
    int temp;
    int temp2;
    int number,caps,specialchar;
    int modes[] = {0,0,0};
    char password[BUFSIZE];
    const char *choices1[] = { "Y - Include caps", "N - No Caps", 0};
    const char *choices2[] = { "Y - Include Number", "N - No Number", 0};
    const char *choices3[] = { "Y - Include specialchar", "N - No Number", 0};
    printf("Enter Y/N\n");
    caps = menupw(choices1, "> Enter your choice\n");
    if(caps == 'y' || caps == 'Y')
        modes[0] = 1;
    clearerr(stdin);
    number = menupw(choices2, "> Enter your choice\n");
    if(number == 'y' || number == 'Y')
        modes[1] = 1;
    clearerr(stdin);
    specialchar = menupw(choices3, "> Enter your choice\n");
    if(specialchar == 'y' || specialchar == 'Y')
        modes[2] = 1;
    
    if (modes[0] == 0 && modes[1] == 0 && modes[2] == 0){
        for(i = 0; i<length; i++){
            test = 0;
            test2 = mode(test);
            password[i] = (char)test2;
        }
        for(i = 0; i<length; i++){
            printf("%c", password[i]);
        }
    }
    if (modes[0] == 0 && modes[1] == 0 && modes[2] == 1){
        
        for(i = 0; i<length; i++){
            test = 0;
            test2 = mode(test);
            password[i] = (char)test2;
        }
        temp = rand() % length;
        password[temp] = mode(3);
        for(i = 0; i<length; i++){
            printf("%c", password[i]);
        }
        
    }
    if (modes[0] == 0 && modes[1] == 1 && modes[2] == 0){
        for(i = 0; i<length; i++){
            test = 0;
            test2 = mode(test);
            password[i] = (char)test2;
        }
        temp = rand() % length;
        password[temp] = mode(2);
        for(i = 0; i<length; i++){
            printf("%c", password[i]);
        }
        
    }
    if (modes[0] == 0 && modes[1] == 1 && modes[2] == 1){
        for(i = 0; i<length; i++){
            test = 0;
            test2 = mode(test);
            password[i] = (char)test2;
        }
        temp = rand() % length;
        password[temp] = mode(2);
        temp2 = rand() % length;
        while (temp2 == temp){
            temp2 = rand() % length;
        }
        password[temp] = mode(3);
        for(i = 0; i<length; i++){
            printf("%c", password[i]);
        }
    }
    if (modes[0] == 1 && modes[1] == 0 && modes[2] == 0){
        for(i = 0; i<length; i++){
            test = 0;
            test2 = mode(test);
            password[i] = (char)test2;
        }
        temp = rand() % length;
        password[temp] = mode(1);
        for(i = 0; i<length; i++){
            printf("%c", password[i]);
        }
    }
    if (modes[0] == 1 && modes[1] == 0 && modes[2] == 1){
        for(i = 0; i<length; i++){
            test = 0;
            test2 = mode(test);
            password[i] = (char)test2;
        }
        temp = rand() % length;
        password[temp] = mode(1);
        temp2 = rand() % length;
        while (temp2 == temp){
            temp2 = rand() % length;
        }
        password[temp] = mode(3);
        for(i = 0; i<length; i++){
            printf("%c", password[i]);
        }
    }
    if (modes[0] == 1 && modes[1] == 1 && modes[2] == 0){
        for(i = 0; i<length; i++){
            test = 0;
            test2 = mode(test);
            password[i] = (char)test2;
        }
        temp = rand() % length;
        password[temp] = mode(1);
        temp2 = rand() % length;
        while (temp2 == temp){
            temp2 = rand() % length;
        }
        password[temp] = mode(2);
        for(i = 0; i<length; i++){
            printf("%c", password[i]);
        }
    }
    if (modes[0] == 1 && modes[1] == 1 && modes[2] == 1){
        for(i = 0; i<length; i++){
            test = rand() % 4;
            test2 = mode(test);
            password[i] = (char)test2;
        }
        /* this ensures that there's at least a special character,  trying to figure out how to make sure for each case */ 
        temp = rand() % length;
        password[temp] = mode(3);
        for(i = 0; i<length; i++){
            printf("%c", password[i]);
        }
    }

}

int menupw(const char *choices[], const char *prompt){
    char line[BUFSIZE];
  while(1){  
    size_t i;
    for(i=0;choices[i]!=0;i++){
        printf("%s\n",choices[i]);
    }
    printf("%s\n", prompt);
    if(!fgets(line, BUFSIZE,stdin)){
        clearerr(stdin);
        fprintf(stderr,"No Input\n");
        return 0;
    } 
    if(line[0] == 'y' || line[0] == 'Y' ||line[0] == 'N' || line[0] == 'n')   {
        return line[0];       
     }
      /*
    c = fgetc(stdin);
     if(c == 'y' || c == 'Y' || c == 'N' || c == 'n')   {
        return c;       
     }
     */
  }
  return 0;
}

int mode(int num){
    switch(num){
        case 0 :
            return (rand() % 25 + 97);
            break;
                
        case 1 :
            return (rand() % 10 + 48);
            break;
        case 2 :
            return (rand() % 25 + 65);
            break;
        case 3 :
            return (rand() % 14 + 33);
            break;
            
    }
    return 0;
    
}


int get_valid_int(const char prompt[], int eof,int min, int max){
    int n;
    while(1){
        n = get_int(prompt,eof);
        if(n == eof)
            return eof;
        if(n>=min && n<=max)
            return n;
    }
}

int get_int(const char prompt[], int eof){
    char line[LINESIZE];
    int n;
    while(1){
        printf("%s\n", prompt);
        if(!fgets(line, LINESIZE,stdin)){
            clearerr(stdin);
            printf("No Input\n");
            return eof;
        } 
        if(sscanf(line, " %d", &n)==1)
            return n;
    }
}
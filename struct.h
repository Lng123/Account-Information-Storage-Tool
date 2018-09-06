#ifndef RECORD_H
#define RECORD_H
#define ISIZE 50
#define NSIZE 25
#define BUFSIZE 256
typedef struct {
	char username[NSIZE];
	char password[NSIZE];
	char site[ISIZE];
}account;

#endif
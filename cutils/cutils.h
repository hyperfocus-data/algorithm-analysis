#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Functions
int * allocIntV(int n);
char * allocStr(int n);
void write(char* outname, const char* buffer);

// Code errors
#define EX_MEMOALLOC 2


// Sys errors
#define EX_INSUFICIENTARGS 70
#define EX_WRONGARG_TYPE 71

// MSGS
#define MSG_EX_WRONGARGS_TYPE "Argumentos errados e/ou insuficientes.\n"

// INCREMENT:OPERATIONS(COUNT) MACRO PRINT
#define INC_PER_COUNT(i, count) printf("%d:%d\n", i, count);
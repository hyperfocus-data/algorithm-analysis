#include<stdlib.h>
#include<stdio.h>
#include "cutils/cutils.h"

#define MSG_USAGE "Usage: ./compile.c <pathfile> <arguments(optional)>\n"

FILE * openPipe(const char * command, const char * mode)
{
    FILE *pipe = popen(command, mode);
    if (pipe == NULL) return NULL;
    return pipe;
}

char * getpipebuffer(const char * command)
{
    char * aux = allocStr(128);
    char * buffer = allocStr(128);
    int i = 0;
    FILE * pipe = openPipe(command, "r");
    if (pipe != NULL)
    {
        if (buffer != NULL && aux != NULL)
        {
            strcpy(aux, ""); // Inicializa o array usando uma string vazia
            while(fgets(buffer, sizeof(buffer), pipe) != NULL)
                strcat(aux, buffer);
            free(buffer);
            return aux;
        }
    }
}

char checksys()
{
    #ifdef __linux__
        printf("OS: Linux.\n");
        return 'l';
    #elif ___WIN32:
        printf("OS: Windows.\n");
        return 'w';
    #endif
}

int main(int argc, char * argv[])
{
    if (argc < 2)
    { printf(MSG_USAGE); exit(EX_INSUFICIENTARGS); }
    else
    {
        if (checksys() == 108) // 108 == l in ASCII
        {
            char * pwd = getpipebuffer("pwd");
            printf("command output: %s\n", pwd);
            char * cddir = allocStr(128);
            strcpy(strcat("cd ", pwd), "");
            
        }
    }
    return 0;
}
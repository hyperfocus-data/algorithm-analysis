#include "cutils.h"

int * allocIntV(int n)
{
    int * v = (int*)malloc(n*sizeof(int));
    if (v == NULL) return NULL;
    return v;
}

char * allocStr(int n)
{
    char * v = (char*)malloc((n + 1)*sizeof(char));
    if (v == NULL) return NULL;
    return v;
}

void write(char* outname, const char* buffer)
{
    FILE * fp = fopen(outname, "a+");
    if (fp != NULL)
    {
        while(!feof(fp)) 
            fprintf(fp, buffer);
        fclose(fp);
    }
}
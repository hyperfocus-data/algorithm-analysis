#include "../../cutils/cutils.h"

#define MSG_USAGE "Usage: <script_name> <target_function> <operations_count>\n"

/*

Basic for loop:
n = operations count

*/
void f1(int n)
{
    int count = 1;
    int i;
    for(i = 1; i < n; i++)
    {
        INC_PER_COUNT(i, count);
        count++;
    }
}

void f2(int n)
{
    int count = 1;
    int i;
    for(i = 1; i < n; i=i+i)
    {
        INC_PER_COUNT(i, count);
        count++;
    }
}

void f3(int n)
{
    int count = 1;
    int i, j;
    for(i=1; i<n; i++)
    {
        for (j=1; j<n; j=j+j)
        {
            INC_PER_COUNT(i, count);
            count++;
        }
    }
}

void f4(int n)
{
    int count = 1;
    int i, j, k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            for(k=0; k<n; k++)
            {
                INC_PER_COUNT(i, count);
                count++;      
            }
        }
    }
}

void f5(int n)
{
    int count = 1;
    int i, j, k;
    for(i=0; i<n; i++)
    {
        for(j=i; j<i+2; j++)
        {
            for(k=0; k<n; k++)
            {
                INC_PER_COUNT(i, count);
                count++;   
            }
        }
    }
}

int main (int argc, char *argv[])
{
    if (argc <= 1) 
    { printf(MSG_USAGE); exit(EX_INSUFICIENTARGS); }
    else 
    {
        //printf("arg 0: %s, arg 1: %s, arg 2: %s\n", argv[0], argv[1], argv[2]);
        if (atoi(argv[1]) == 1)
            f1(atoi(argv[2]));

        else if (atoi(argv[1]) == 2)
            f2(atoi(argv[2]));

        else if (atoi(argv[1]) == 3)
            f3(atoi(argv[2]));

        else if (atoi(argv[1]) == 4)
            f4(atoi(argv[2]));

        else if (atoi(argv[1]) == 5)
            f5(atoi(argv[2]));
        else 
        { printf(MSG_EX_WRONGARGS_TYPE); exit(EX_WRONGARG_TYPE); }
    }
}
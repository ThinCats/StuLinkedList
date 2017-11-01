#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n)
{
    char * ret;
    char * isRet;

    ret = fgets(st, n, stdin);
    if(ret)
    {
        isRet = strchr(st, '\n');
        if(isRet)
            *isRet = '\0';   //Block the '\n'

        else
            while(getchar() != '\n')
                continue;             //delete the other char;
    }

    return ret;
}

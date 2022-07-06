#include "headers.h"

void pwd(int rdhere, int wrthere)
{
    int realin,realout,red;
	realin=dup(STDIN_FILENO);
	realout=dup(STDOUT_FILENO);

	if(rdhere!=STDIN_FILENO)
	{
        dup2(rdhere,STDIN_FILENO);
	}
    if(wrthere!=STDOUT_FILENO)
	{
        dup2(wrthere,STDOUT_FILENO);
	}
 

    char path[10240];
    getcwd(path, 10240);

    if(strlen(path) == strlen(home_path))
    {
        printf("%s\n",home_path);
    }
    else if(strlen(path) > strlen(home_path))
    {
        // printf("~");
        printf("%s",home_path);

        int var;
        var = strlen(path) - strlen(home_path);
        for(int i = strlen(home_path);i<strlen(path);i++)
        {
            printf("%c",path[i]); //***** DOUBT CLEAR CORRECT OR NOT *****//
        }
        printf("\n");
    }
    else
    {
        printf("%s\n",path);
    }

    if(rdhere!=STDIN_FILENO)
	{
        dup2(realin,STDIN_FILENO);
	}
    if(wrthere!=STDOUT_FILENO)
	{
        dup2(realout,STDOUT_FILENO);
	}
	red=close(realin);
	red=close(realout);
}

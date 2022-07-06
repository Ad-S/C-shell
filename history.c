#include "headers.h"

void history(int rdhere, int wrthere , char *inp)
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

    int histno = -1;

    char* token1 = strtok(inp, " ");
    token1 = strtok(NULL, " ");

    while(token1 != NULL)
    {
        histno = atoi(token1);
        token1 = strtok(NULL, " ");
    }

    if(histno == -1)
    {
        if(histcmd >= 10)
        {
            for(int i = histcmd - 10 ; i < histcmd ; i++ )
            {
                printf("%s\n",hist[i]);
            }
        }
        else
        {
            for(int i = 0; i < histcmd ; i++)
            {
                printf("%s\n",hist[i]);
            }
        }   
    }
    else
    {
        if(histcmd >= histno)
        {
            for(int i = histcmd - histno ; i < histcmd ; i++ )
            {
                printf("%s\n",hist[i]);
            }
        }
        else
        {
            for(int i = 0; i < histcmd ; i++)
            {
                printf("%s\n",hist[i]);
            }
        }
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
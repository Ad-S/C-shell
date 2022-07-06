// #include "prompt.h"
#include "headers.h"
// #include "inputgiven.h"
// #include "echo1.h"
// #include "cd.h"
// #include "ls.h"
// #include "foreground.h"

void fg(int rdhere, int wrthere , char *inp)
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

	int forkReturn = fork();

    // printf("hehe\n");

	if (forkReturn == 0)
    {
        // printf("hehe1\n");

        // char cmd[1000][1000];

        signal(SIGINT,SIG_DFL);

		char *cmd[1000];

        char* token1 = strtok(inp, " ");
        // token1 = strtok(NULL, " ");

        int var = 0;

        while (token1 != NULL)
        {
            cmd[var] = (char *)malloc(strlen(token1)* sizeof(char));
            strcpy(cmd[var],token1);
            token1 = strtok(NULL, " ");
            var++;
        } 
        cmd[var] = NULL;

        // printf("%s",cmd[0]);

        int x = execvp(cmd[0],cmd);

        if(x == -1)
        {
            perror("no command");
            exit(1);
        }
        
    }
    else
    {
		wait(NULL);

        signal(SIGINT,SIG_IGN);
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
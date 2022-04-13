// #include "prompt.h"
#include "headers.h"
// #include "inputgiven.h"
// #include "echo1.h"
// #include "cd.h"
// #include "ls.h"
// #include "foreground.h"
// #include "background.h"

void bg(int rdhere, int wrthere , char *inp)
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

    char *cmd[1000];

    char* token1 = strtok(inp, " ");
    // token1 = strtok(NULL, " ");

    int var = 0;

    while (token1 != NULL)
    {
        if(strcmp(token1,"&") != 0){
        cmd[var] = (char *)malloc(strlen(token1)* sizeof(char));
        strcpy(cmd[var],token1);
        token1 = strtok(NULL, " ");
        var++;
        }
        else
        {
            token1 = strtok(NULL, " ");
        }
    } 
    cmd[var] = NULL;

	int forkReturn = fork();
    


    // printf("hehe\n");

	if (forkReturn == 0)
    {

        // printf("hehe1\n");

        // char cmd[1000][1000];
		

        int var1 = getpid();
		setpgid(var1,var1);

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
		setpgid(forkReturn,forkReturn);
		tcsetpgrp(STDIN_FILENO, getpgid(getpid()));

		// printf("[%d] %d\n",((*bgproct)+1),ref);  // DOUBT [%d]???

        printf("%d\n",forkReturn);

        allbgpid[noofbg] = forkReturn;
        strcpy(allbgcmd[noofbg],cmd[0]);

        noofbg ++;
        // printf("forkret%d\n",forkReturn);


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

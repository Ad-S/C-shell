#include "headers.h"

void pinfo(int rdhere, int wrthere , char *inp)
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

    int pid=getpid();


    char *cmd[1000];

    char* token1 = strtok(inp, " ");

    int var = 0;

    while (token1 != NULL)
    {
        if(strcmp(token1,"pinfo") != 0){
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

	char path[1000];

    // int filepid;

    if(var == 0)
    {
		sprintf(path,"/proc/%d/stat",pid);
        printf("pid -- %d\n", pid);
    }
    else
    {
		sprintf(path,"/proc/%s/stat",cmd[0]);
        printf("pid -- %s\n", cmd[0]);
    }



	int fd=open(path,O_RDONLY);
    if(fd == -1)
    {
        perror("cannot open file");
    }

    char data[1000];
	read(fd,data,1000);
    char data2[1000][1000];
    int x1=0;
    int y1=0;

    char* token2 = strtok(data, " ");
    // token2 = strtok(NULL, " ");

    while(token2 != NULL)
    {
        strcpy(data2[x1],token2);
        token2 = strtok(NULL, " ");
        x1++;
    }

    // printf("%s\n",data2);
    // for(int c=0;c < x1 )
    if(var != 0)
    {
        pid = atoi(cmd[0]);
    }


    if(getpgid(pid) == tcgetpgrp(STDIN_FILENO))
        printf("Process Status -- %s+\n",data2[2]);
    else
        printf("Process Status -- %s\n",data2[2]);

    printf("Memory ​ --%s\n",data2[22] );

    sprintf(path ,"/proc/%d/exe",pid);
	int l = readlink(path ,data,1000);
	if(l<0)
	{
		perror("error in opening exe file of given pid\n");
	}
	data[l]='\0';
	printf("Executable path -- %s\n",data);

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
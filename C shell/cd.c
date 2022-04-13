// #include "prompt.h"
#include "headers.h"
// #include "inputgiven.h"
// #include "echo1.h"
// #include "cd.h"

void cd(int rdhere , int wrthere , char *inp)
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
    memset(path,0,strlen(path));
    // char *path;
	// path = (char *)malloc(10000);
    // printf("inpobt %s\n",inp);
    // printf("%ld\n",strlen(inp));


    int var = 0;
    for(int i=0;i<strlen(inp);i++)
    {
        if(inp[i] == ' ')
        {
            var = i + 1;
            break;
        }
    }
    // printf("var %d\n",var);
    int var2 = var;
    char temp[2] = "";

    if(var == 0)
    {
        strcpy(path,home_path);
    }
    else
    {
        if(inp[var2] == '~')
        {
            strcpy(path,home_path);
            var++;
        }
        else if(inp[var2] == '-')
        {
            strcpy(path,oldpath);
            var++;
        }
        for(int i =var; i<strlen(inp) ;i++)
        {
            temp[0] = inp[i];
            temp[1] = '\0';
            // printf("temp %s\n",temp);
            strcat(path,temp);
        }
        
    }
    // printf("path %s\n",path);

    getcwd(oldpath, 1024);


    int var3=chdir(path);
	if(var3 < 0)
	{
		//handle error
		perror("->");
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

    // doubt if only cd is passed not going in if loop
    
}
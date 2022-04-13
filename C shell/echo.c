// #include "prompt.h"
#include "headers.h"
// #include "inputgiven.h"
// #include "echo1.h"

void echo(int rdhere, int wrthere , char *inp)
{
    // printf("hehe\n");
    // printf("inpobt %s\n",inp);

    // printf("IN echo %d %d %d\n",STDIN_FILENO,STDOUT_FILENO,wrthere);
    int realin,realout,red;
	realin=dup(STDIN_FILENO);
	realout=dup(STDOUT_FILENO);


	if(rdhere!=STDIN_FILENO)
	{
        // printf("asdadsasd\n");
        dup2(rdhere,STDIN_FILENO);
	}
    if(wrthere!=STDOUT_FILENO)
	{
        // printf("herealreat");

        dup2(wrthere,STDOUT_FILENO);
	}

    char* token1 = strtok(inp, " ");
    token1 = strtok(NULL, " ");

    while (token1 != NULL) 
    {
        // fprintf(wrthere,"%s ", token1);
        write(wrthere,token1,strlen(token1));
        write(wrthere," ",1);
        token1 = strtok(NULL, " ");
    }
	// write(wrthere ,"\n", sizeof("\n"));


    // int var=0;
    // while(inp[var] != '"')
    // {
    //     var++;
    // }
    // // printf("%ld",strlen(inp));
    // // var++;

    // for(int i = var;i<strlen(inp);i++)
    // {
    //     // printf("hehe\n");

    //     if(inp[i] != '"'){
    //     printf("%c",inp[i]);
    //     }

    // }

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

    printf("\n"); //fix this

    

}

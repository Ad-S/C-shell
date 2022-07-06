#include "headers.h"

void repeat(int rdhere, int wrthere , char *inp)
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

    int nooftime;
    // char *temp;
	// temp = (char *)malloc(1000);
    char temp[10240];
    memset(temp,0,strlen(temp));

    char* token1 = strtok(inp, " ");
    token1 = strtok(NULL, " ");
    nooftime = atoi(token1);
    token1 = strtok(NULL, " ");


    while (token1 != NULL) 
    {
        if(temp == NULL)
        {
            strcpy(temp,token1);
        }
        else
        {
            strcat(temp,token1);
        }
        strcat(temp," ");
        
        
        token1 = strtok(NULL, " ");
    }

    // printf("%d\n",nooftime);
    // printf("%s\n",temp);
    while(nooftime != 0){
    char krt[10240];
    strcpy(krt,temp);
    // printf("tempk %s\n",krt);
    inputgiven(rdhere, wrthere , krt);
    nooftime--;
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

//     char temp1[100000];
//     strcpy(temp1,temp);
//     temp1[strlen(temp)] = '\0';

//     char *temp2;
// 	temp2 = (char *)malloc(1000);


//     char* token2 = strtok(temp, " ");
//     strcpy(temp2,token2);
//     // printf("yoyo %s\n", temp);
//     // if(strcmp(temp,"") == 0)
//     // {
//     //     strcpy(temp,inp);
//     // }

//     int bgflag = 0;

//     while (token2 != NULL) 
//         {
//             if(strcmp(token2,"&") == 0)
//             {
//                 bgflag = 1;
//             }
//             // if(strcmp(token1 ,cdstr) == 0)
//             // {
//             //     printf("do cd function");
                
//             // }
//             // printf("%s\n", token);
//             token2 = strtok(NULL, " ");
//         }

//     int no2 = nooftime;
//     while(no2 != 0){

//     if(bgflag == 1)
//     {
//         // printf("do backgrd\n");
//         while(nooftime != 0){
//         bg(temp1);
//         nooftime--;
//         }
//     }
//     else if(strcmp(temp2 ,"cd") == 0 )
//     {
//         // printf("do cd function\n");
//         while(nooftime != 0){
//         cd(temp1);
//         nooftime--;
//         }
//     }
//     else if(strcmp(temp2,"echo") == 0)
//     {
//         // printf("do echo function\n");
//         while(nooftime != 0){
//         echo(temp1);
//         nooftime--;
//         }
        
//     }
//     else if(strcmp(temp2,"pwd") == 0)
//     {
//         // printf("do pwd function");
//         while(nooftime != 0){
//         pwd();
//         nooftime--;
//         }
        
//     }
//     else if(strcmp(temp2,"repeat") == 0)
//     {
//         // printf("do pwd function");
//         while(nooftime != 0){
//         repeat(temp1);
//         nooftime--;
//         }
        
//     }
//    else if(strcmp(temp2,"ls") == 0)
//     {
//         // printf("do ls function\n");
//         while(nooftime != 0){
//         ls(temp1);
//         nooftime--;
//         }
        
//     }
//     else
//     {
//         // printf("i m in");
//         while(nooftime != 0){
//         fg(temp1);
//         nooftime--;
//         }
//     }
//     no2--;
//     }

}
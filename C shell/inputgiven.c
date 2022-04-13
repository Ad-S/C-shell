// #include "prompt.h"
#include "headers.h"
// #include "inputgiven.h"
// #include "echo1.h"
// #include "cd.h"
// #include "ls.h"
// #include "foreground.h"
// #include "background.h"

int inputgiven(int rdhere, int wrthere ,char *inp)
{

    // printf("inpobt %s\n",inp);

    // int i, j, len;
    // len = strlen(inp);
    // char string[len];
    // for(i=0; i<len; i++) {
    //     if(inp[0]==' ') {
    //         for(i=0; i<(len-1); i++)
    //         inp[i] = inp[i+1];
    //         inp[i] = '\0';
    //         len--;
    //         i = -1;
    //         continue;
    //     }
    //     if(inp[i]==' ' && inp[i+1]==' ') {
    //         for(j=i; j<(len-1); j++) {
    //             inp[j] = inp[j+1];
    //         }
    //         inp[j] = '\0';
    //         len--;
    //         i--;
    //     }
    // }

    char vartemp1[10240];
    memset(vartemp1,0,strlen(vartemp1));

    char vartemp[10000];
    strcpy(vartemp,inp);
    vartemp[strlen(inp)] = '\0';

    char* token2 = strtok(vartemp, "\t");


    while (token2 != NULL) 
    {
        if(vartemp1 == NULL)
        {
            strcpy(vartemp1,token2);
        }
        else
        {
            strcat(vartemp1,token2);
        }
        // if(token2 != NULL)
        // strcat(vartemp1," ");
        
        token2 = strtok(NULL, "\t");
    }

    // printf("newinp %s\n",vartemp1);
    strcpy(inp,vartemp1);


    // printf("commands %s\n",inp);
    char temp1[100000];
    strcpy(temp1,inp);
    temp1[strlen(inp)] = '\0';
    char temp3[100000];
    strcpy(temp3,inp);
    temp3[strlen(inp)] = '\0';


    // char cdstr[2] = "cd";
    // char echostr[4] = "echo";
    // char pwdstr[3] = "pwd";

    // char temp[1000] = "";
    // int var=0;
    // while(inp[var] != ' ')
    // {
    //     printf("value %c\n",inp[var]);    
    //     temp[var] = inp[var];
    //     var++;
    // }
    // temp[var] = "\0";
	char *temp;
	temp = (char *)malloc(1000);


    if(strcmp(inp,"") != 0)
    // printf("hehe1%shehe1\n",inp);
    {

    char* token1 = strtok(inp, " ");
    strcpy(temp,token1);

    // printf("hehe\n");

    // printf("yoyo %s\n", temp);
    // if(strcmp(temp,"") == 0)
    // {
    //     strcpy(temp,inp);
    // }

    int bgflag = 0;
    int  pipeflag = 0;

    while (token1 != NULL) 
        {
            if(strcmp(token1,"&") == 0)
            {
                bgflag = 1;
            }
            if(strcmp(token1,"|") == 0)
            {
                pipeflag = 1;
            }
            // if(strcmp(token1 ,cdstr) == 0)
            // {
            //     printf("do cd function");
                
            // }
            // printf("%s\n", token);
            token1 = strtok(NULL, " ");
        }

    // printf("temp%s\n",temp);  ////// *********************************************************** ///////////////////////
    
    if(pipeflag == 1)
    {
        int pvar = 0;
        char *cmds[1000];
        // char* ptoken = strtok(temp1, "|");
        cmds[pvar]= strtok(temp1, "|");
        while (cmds[pvar] != NULL) 
        {
            // printf("%s\n", token);
            // strcpy(cmds[pvar],ptoken);
            pvar++;
            // inputgiven(token);
            cmds[pvar] = strtok(NULL, "|");
        }
        // printf("helloji %d\n",pvar);
        do_pipe(rdhere,wrthere,pvar,cmds);
        return 0;

    }

    // chk whether we have to redirect 
    if(redirt(rdhere,wrthere,temp1) == 1)
    {
        return 0;
    }

    // printf("ininp");


    if(strcmp(hist[histcmd-1],temp3) != 0)
    {
    strcpy(hist[histcmd],temp3);  
    histcmd++;
    }

    if(bgflag == 1)
    {
        // printf("do backgrd\n");
        bg(rdhere, wrthere , temp1);
    }
    else if(strcmp(temp ,"cd") == 0 )
    {
        // printf("do cd function\n");
        cd(rdhere, wrthere , temp1);   
    }
    else if(strcmp(temp,"echo") == 0)
    {
        // printf("in input%d\n",wrthere);

        echo(rdhere, wrthere , temp1);
        
    }
    else if(strcmp(temp,"pwd") == 0)
    {
        // printf("do pwd function");
        pwd(rdhere, wrthere);
        
    }
    else if(strcmp(temp,"repeat") == 0)
    {
        // printf("do pwd function");
        repeat(rdhere, wrthere , temp1);
        
    }
   else if(strcmp(temp,"ls") == 0)
    {
        // printf("do ls function\n");
        ls(rdhere, wrthere , temp1);
        
    }
    else if(strcmp(temp,"pinfo") == 0)
    {
        // printf("do ls function\n");
        pinfo(rdhere, wrthere , temp1);
        
    }
    else if(strcmp(temp,"exit") == 0)
    {
        // printf("do ls function\n");
        run = 0;
    }
    else if(strcmp(temp,"history") == 0)
    {
        // printf("do ls function\n");
        history(rdhere, wrthere , temp1);
    }
    else if(strcmp(temp,"jobs") == 0)
    {
        // printf("addkar\n");
        // fflush(stdout);
        jobs(rdhere, wrthere , temp1);
    }
    else if(strcmp(temp,"sig") == 0)
    {
        jobs(rdhere, wrthere , temp1);
    }
    else if(strcmp(temp,"fg") == 0)
    {
        jobs(rdhere, wrthere , temp1);
    }
    else
    {
        // printf("i m in");
        fg(rdhere, wrthere , temp1);
    }
    }

    
    
    // while (token1 != NULL) 
    // {
    //     // printf("%s\n", token);
    //     token1 = strtok(NULL, " ");
    // }
    // printf("%s\n",temp);

    

    


}
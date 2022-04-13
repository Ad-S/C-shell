#include "headers.h"

int redirt(int rdhere, int wrthere, char *str)

{
    // printf("helloboi\n");
    int len;
    int flag1 = 0; // for <
    int flag2 = 0; // for >
    int flag3 = 0; // for >>
    char cstr[1024];
    strcpy(cstr,str);
    len = strlen(cstr);

    // printf("%s",cstr);

    for(int i =0; i < len ; i++)
    {
        if(cstr[i] == '<')
        {
            flag1 = 1;
            cstr[i] = ';';
        }   
        else if(cstr[i] == '>')
        {
            cstr[i] = ';';
            if(i < len-1)
            {
                i++;
            }
            if(cstr[i] == '>')
            {
                flag3 = 1;
                cstr[i] = ';';
            }
            else
            {
                flag2 = 1;
            }
        }
    }

    // printf("%d , %d , %d",flag1,flag2,flag3);

    if(flag1 == 1 && flag2 == 1)
    {
        char* token = strtok(cstr, ";");
        char* token1 = strtok(NULL, ";"); // new input file
        char* token2 = strtok(NULL, ";"); // new output file

        int newinp =0;
        int newout =0;

		char *file = strtok(token1," ");
		newinp=open(file,O_RDONLY);

		char *file1 = strtok(token2," ");
        newout=open(file1,O_RDWR| O_CREAT, 0644);

        inputgiven(newinp,newout,token);

        return 1;

    }
    else if(flag1 == 1 && flag3 == 1)
    {
        char* token = strtok(cstr, ";");
        char* token1 = strtok(NULL, ";"); // new input file
        char* token2 = strtok(NULL, ";"); // new output file

        int newinp =0;
        int newout =0;

		char *file = strtok(token1," ");
		newinp=open(file,O_RDONLY);

		char *file1 = strtok(token2," ");
        newout=open(file1,O_RDWR| O_APPEND | O_CREAT , 0644);

        inputgiven(newinp,newout,token);
        return 1;

        
    }
    else if(flag1 == 1)
    {

        char* token = strtok(cstr, ";");
        char* token1 = strtok(NULL, ";"); // new input file
        // char* token2 = strtok(NULL, ";"); // new output file

        int newinp =0;
        int newout =0;

		char *file = strtok(token1," ");
		newinp=open(file,O_RDONLY);

		// char *file = strtok(token2," ");
        // newout=open(file,O_RDWR| O_APPEND | O_CREAT , 0644);

        inputgiven(newinp,wrthere,token);
        return 1;
        
    }
    else if(flag2 == 1 || flag3 == 1)
    {
        // printf("asdasd");
        char* token = strtok(cstr, ";");
        // char* token1 = strtok(NULL, ";"); // new input file
        char* token2 = strtok(NULL, ";"); // new output file

        int newinp =0;
        int newout =0;

		// char *file = strtok(token1," ");
		// newinp=open(file,O_RDONLY);

        if(flag3 == 1)
        {            
            char *file = strtok(token2," ");
            newout=open(file,O_RDWR| O_APPEND | O_CREAT , 0777);
        }
        else if(flag2 == 1)
        {
            char *file = strtok(token2," ");
            newout=open(file,O_RDWR| O_CREAT , 0777); 
        }

        // printf("rd %d , wr %d\n", rdhere , newout);

        inputgiven(rdhere,newout,token);
        return 1;

    }
    else if(flag1 == 0 && flag2 == 0 && flag3 == 0)
    {
        return 0;
    }
    
}
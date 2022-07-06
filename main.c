// #include "prompt.h"
#include "headers.h"
// #include "inputgiven.h"
// #include "echo1.h"
// #include "background.h"

int main()
{
    getcwd(home_path,1024);
    getcwd(oldpath,1024);

    signal(SIGINT,SIG_IGN);

    noofbg = 0;
    histcmd = 0;
    for(int yum = 0;yum < 10000 ; yum ++)
    {
        allbgpid[yum] = -1;
    }
    run = 1;
    while (run == 1)
    {
        // lets get the home dir path 
        // printf("%s\n",home_path);

        prompt();

        


        char a[1024];
        // scanf("%s", a);

        // TAKE INPUT HERE
        char *buffer;
        size_t bufsize = 32;
        size_t characters;

        buffer = (char *)malloc(bufsize * sizeof(char));
        if( buffer == NULL)
        {
            perror("Unable to allocate buffer");
            exit(1);
        }
        characters = getline(&buffer,&bufsize,stdin);
        if(characters == -1)
        {
            run = 0;
            continue;
        }
        
        buffer[strlen(buffer)-1] = '\0';
        // printf("%s",buffer); // will print the whole input

		// signal(SIGINT,SIG_IGN); iska use

        char temp[1024][1024];
        int var1,var2;
        var1=0;
        // printf("hello\n");

        char* token = strtok(buffer, ";");
        while (token != NULL) 
        {
            // printf("%s\n", token);
            strcpy(temp[var1],token);
            var1++;
            // inputgiven(token);
            token = strtok(NULL, ";");
        }
        for(int var3=0;var3<var1;var3++)
        {
            // if(strcmp(temp[var3],"exit") == 0)
            // {
            //     run = 0;
            //     break;
            // }
            inputgiven(0,1,temp[var3]);
        }

        //check if background process is ended

        int stat,chkexit;

        for(int var3 = 0;var3 < noofbg; var3++)
        {
            if(allbgpid[var3] == -1)
            {
                continue;
            }
            else
            {
                chkexit=waitpid(allbgpid[var3],&stat,WNOHANG);
                // printf("yoyoyo%d\n",chkexit);
                if(chkexit != 0)
                {
                    // printf("asdsa\n");
                    if(WIFEXITED(stat))
                    {
                        printf("%s with pid %d exited normally\n",allbgcmd[var3],allbgpid[var3]);
                    }
                    else
                    {
                        printf("%s with pid %d exited abnormally\n",allbgcmd[var3],allbgpid[var3]);
                    }
                    allbgpid[var3] = -1;
                }
                
            }
            
        }

        

    }
}

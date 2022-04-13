#include "headers.h"

void jobs(int rdhere, int wrthere, char *str)
{
    // printf("injobs");
    // fflush(stdout);

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

    char* token = strtok(str, " ");
    char* token1 = strtok(NULL, " ");
    char* token2 = strtok(NULL, " ");
    // char* token3 = strtok(NULL, " ");
    // printf("injobs\n");
    // fflush(stdout);


    if(strcmp(token,"jobs") == 0)
    {
        int flags = 0;
        int flagr = 0;

        if(token1 != NULL && strcmp(token1,"-r") == 0)
        flagr = 1;

        if(token1 != NULL && strcmp(token1,"-s") == 0)
        flags = 1;

        int i = 0;
        int cnt = 0;
        while(i<10000)
        {
            if(allbgpid[i] != -1)
            {
                cnt++;
                char *path=(char *)malloc(1000*sizeof(char));
                sprintf(path,"/proc/%d/status",allbgpid[i]);
                if(path==NULL)
                    printf("Malloc failed");

                FILE *f= fopen(path,"r");
                
                char *string; // character array pointer
                size_t size = 1000; // initial size of char array
                string = (char*) malloc (size);//dynamic memory allocation of character array

                char *prname; // character array pointer
                // size_t size = 1000; // initial size of char array
                prname = (char*) malloc (size);//dynamic memory allocation of character array

                getline(&string,&size, f);
                sscanf(string,"Name: \t%s",prname);
                getline(&string,&size, f);
                getline(&string,&size, f);
                char state;
                sscanf(string,"State: \t%c",&state);



                if(flags == 1)
                {
                    if(state == 'T')
                    {
                        printf("[%d]  ", cnt);
                        printf("Stopped ");
                        printf("%s ",prname);
                        printf("%d\n",allbgpid[i]);
                    }
                }
                else if(flagr == 1)
                {
                    if(state != 'T')
                    {
                        printf("[%d]  ", cnt);
                        printf("Running ");
                        printf("%s ",prname);
                        printf("%d\n",allbgpid[i]);
                    }
                }
                else
                {
                    if(state == 'T')
                    {
                        printf("[%d]  ", cnt);
                        printf("Stopped ");
                        printf("%s ",prname);
                        printf("%d\n",allbgpid[i]);
                    }
                    else
                    {
                        printf("[%d]  ", cnt);
                        printf("Running ");
                        printf("%s ",prname);
                        printf("%d\n",allbgpid[i]);
                    }
                }
                

            }
            i++;
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
    else if(strcmp(token,"sig") == 0)
    {
        if(token1 == NULL || token2 == NULL)
        {
            printf("sig : Wrong numnber of argumnets\n");
        }
        else
        {
            int flagchk =0;

            int prcnt;
            prcnt = atoi(token1);
            int sig;
            sig = atoi(token2);

            int findcnt =0;
            int i  =0;
            while(i<10000)
            {
                if(allbgpid[i] != -1)
                {
                    findcnt ++;
                    if(findcnt == prcnt)
                    {
                        flagchk = 1;
                        break;
                    }
                }
                i++;
            }
            if(flagchk == 1){
            int a = kill(allbgpid[i],sig);
            if(a == -1)
            {
                perror("Error in kill");
            }
            }
            else
            {
                printf("No job exist with this id\n");
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
    else if(strcmp(token,"fg") == 0)
    {
        if(token1 == NULL)
        {
            printf("sig : Wrong numnber of argumnets\n");
        }
        else
        {
            int flagchk = 0;
            int prcnt;
            prcnt = atoi(token1);

            int findcnt =0;
            int i  =0;
            while(i<10000)
            {
                if(allbgpid[i] != -1)
                {
                    findcnt ++;
                    if(findcnt == prcnt)
                    {
                        flagchk =1;
                        break;
                    }
                }
                i++;
            }
            if(flagchk == 1){
            // int a = kill(allbgpid[i],sig);
            int wstat,bgadd;
            signal(SIGTTOU,SIG_IGN);
            tcsetpgrp(STDIN_FILENO,allbgpid[i]);
            signal(SIGTTOU,SIG_DFL);
            signal(SIGINT,SIG_DFL);
            // signal(SIGTSTP,SIG_DFL);
            // signal(SIGSTOP,SIG_DFL);
            kill(allbgpid[i],SIGCONT);
            // if(a==-1)
            //     printf("kill error");
            waitpid(allbgpid[i],&wstat,WUNTRACED);
            // if(a==-1)
            //     printf("waitpid failed");
            signal(SIGTTOU,SIG_IGN);
            tcsetpgrp(STDIN_FILENO,getpgid(getpid()));
            signal(SIGTTOU,SIG_DFL);
            signal(SIGINT,SIG_IGN);


            if(WIFSTOPPED(wstat))
            {
                int temp =0;
                for(int j = 0  ; j <= i ; j ++ )
                {
                    if(allbgpid[j] != -1)
                    {
                        temp++ ;
                    }
                }
                printf("\n[%d] %d\n",temp,allbgpid[i]);

            }
            else
            {
                allbgpid[i] = -1;
            }
            }
            else
            {
                printf("No job exist with this id\n");
            }
            // signal(SIGTTOU,SIG_DFL);
            // signal(SIGINT,SIG_IGN);
            // signal(SIGTSTP,SIG_IGN);
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
}


#include "headers.h"

void do_pipe(int rdhere, int wrthere ,int nocmd, char **cmds)
{
    // printf("hereiam %d ",nocmd);

    int i  = 0;
    int fildes[2];
    for(i = 0;i< nocmd;i++)
    {
        if(i == nocmd-1)
        {
            char temp[1000];
            strcpy(temp,cmds[i]);
            if (pipe(fildes) < 0)
            {
                perror("Could not create pipe.");
                exit(1);
            }
            inputgiven(rdhere,1,temp);
        }
        else
        {
            char temp[1000];
            strcpy(temp,cmds[i]);
            if (pipe(fildes) < 0)
            {
                perror("Could not create pipe.");
                exit(1);
            }
            inputgiven(rdhere,fildes[1],temp);
            close(fildes[1]);
            rdhere=fildes[0];
        }
    }

}

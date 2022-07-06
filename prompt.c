// #include "prompt.h"
#include "headers.h"
// #include "echo1.h"

void prompt() {
    char *buf;
    buf=(char *)malloc(10*sizeof(char));
    buf=getlogin();
    if(buf == NULL)
    {
        perror("username error");
    }

    char hostname[1024];
    int v = gethostname(hostname, 1024);
    if(v == -1)
    {
        perror("hostname error");
    }

    printf("<%s@%s:",buf,hostname);

    char path[10240];
    getcwd(path, 10240);
    // printf("%s>",path);

    if(strlen(path) == strlen(home_path))
    {
        printf("~>");
    }
    else if(strlen(path) > strlen(home_path))
    {
        printf("~");
        int var;
        var = strlen(path) - strlen(home_path);
        for(int i = strlen(home_path);i<strlen(path);i++)
        {
            printf("%c",path[i]); //***** DOUBT CLEAR CORRECT OR NOT *****//
        }
        printf(">");
    }
    else
    {
        printf("%s>",path);
    }
    

}

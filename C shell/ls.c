// #include "prompt.h"
#include "headers.h"
// #include "inputgiven.h"
// #include "echo1.h"
// #include "cd.h"
// #include "ls.h"

void ls(int rdhere, int wrthere , char *inp)
{
    // extract all flags
    // printf("inpobt %s\n",inp);

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

    int flaga = 0;
    int flagl = 0;
    int var;
    char pathfile[1024] = "";
    char permission[11];

    for(int i = 0; i < strlen(inp) ; i++)
    {
        if(inp[i] == '-')
        {
            var = i;
            while(inp[i] != ' ')
            {
                if(var == strlen(inp))
                break;
                if(inp[var] == 'a')
                {
                    flaga = 1;
                }
                if(inp[var] == 'l')
                {
                    flagl = 1;
                }
                var++;
            }
        }
    }

    char dirname[1000][1000];
    char* token1 = strtok(inp, " ");
    token1 = strtok(NULL, " ");

    int noofarg = 0;


    while (token1 != NULL) 
    {
        
        // printf("%s\n",token1);
        if(token1[0] != '-')
        {
            // printf("hello\n");
            if(token1[0] == '~')
            {
                strcpy(dirname[noofarg],home_path);
                int len = strlen(home_path);
                for(int i = 1;i < strlen(token1) ; i++)
                {
                    dirname[noofarg][len] = token1[i];
                    len++;
                }
            }
            else
            strcpy(dirname[noofarg],token1);

            noofarg++;
        }
        token1 = strtok(NULL, " ");
    }

	// struct stat cong[noofarg+1];


    if(noofarg == 0)
    {
        strcpy(dirname[noofarg],".");
        noofarg++;
    }
    
    // printf("flags %d%d\n",flaga,flagl);
    for(int i =0 ; i< noofarg ; i++)
    {
        // printf("%s\n",dirname[i]);
		// int j=stat(dirname[i],&cong[i]);
        DIR*p;
        struct dirent *d;
        p=opendir(dirname[i]);

        if(noofarg > 1)
        {
            printf("%s\n",dirname[i]);
        }

        if(flaga == 0 && flagl == 0)
        {

            if(p==NULL)
            {
                perror("Cannot find directory");
                exit(-1);
            }
            while(d=readdir(p))
            {
                if(d->d_name[0] != '.')
                printf("%s\n",d->d_name);
            }
        }

        if(flaga == 1 && flagl == 0)
        {

            if(p==NULL)
            {
                perror("Cannot find directory");
                exit(-1);
            }
            while(d=readdir(p))
            {
                printf("%s\n",d->d_name);
            }
        }

        if(flaga == 1 && flagl == 1)
        {
            if(p==NULL)
            {
                perror("Cannot find directory");
                exit(-1);
            }
            while(d=readdir(p))
            {
                // printf("%s\n",d->d_name);
                strcpy(pathfile,dirname[i]);
                strcat(pathfile,"/");
                strcat(pathfile,d->d_name);
                struct stat sb;

                if(stat(pathfile,&sb)==0)
                {
                    if(S_ISDIR(sb.st_mode))
                        permission[0] = 'd';
                    if(S_ISREG(sb.st_mode))
                        permission[0] = '-'; 	
                    if(sb.st_mode & S_IRUSR)
                        permission[1] = 'r'; 
                    else	
                        permission[1] = '-'; 	
                    if(sb.st_mode & S_IWUSR)
                        permission[2] = 'w';
                    else
                        permission[2] = '-';
                    if(sb.st_mode & S_IXUSR)
                        permission[3] = 'x';
                    else
                        permission[3] = '-';
                    if(sb.st_mode & S_IRGRP)
                        permission[4] = 'r';
                    else
                        permission[4] = '-';
                    if(sb.st_mode & S_IWGRP)
                        permission[5] = 'w';
                    else
                        permission[5] = '-';
                    if(sb.st_mode & S_IXGRP)
                        permission[6] = 'x';
                    else
                        permission[6] = '-';
                    if(sb.st_mode & S_IROTH)
                        permission[7] = 'r'; 
                    else
                        permission[7] = '-'; 
                    if(sb.st_mode & S_IWOTH)
                        permission[8] = 'w';
                    else
                        permission[8] = '-';
                    if(sb.st_mode & S_IXOTH)
                        permission[9] = 'x';
                    else
                        permission[9] = '-';
                    }
                    permission[10] = '\0';
                    printf("%s",permission);
                    printf("  %ld %s %s", sb.st_nlink,getpwuid(sb.st_uid)->pw_name,getgrgid(sb.st_gid)->gr_name);
                    printf("%13ld ", sb.st_size);
                    // printf("%s %s\n", ctime(&(sb.st_mtime))+4,d->d_name);
                    struct tm dt;
                    dt = *(gmtime(&sb.st_ctime));
                    printf("%d-%d-%d  ", dt.tm_mday, dt.tm_mon, dt.tm_year + 2000);
                    printf("%s\n",d->d_name);
                    
            }
        }
        if(flaga == 0 && flagl == 1)
        {
            if(p==NULL)
            {
                perror("Cannot find directory");
                exit(-1);
            }
            while(d=readdir(p))
            {
                if(d->d_name[0] != '.'){

                // printf("%s\n",d->d_name);
                strcpy(pathfile,dirname[i]);
                strcat(pathfile,"/");
                strcat(pathfile,d->d_name);
                struct stat sb;

                if(stat(pathfile,&sb)==0)
                {
                    if(S_ISDIR(sb.st_mode))
                        permission[0] = 'd';
                    if(S_ISREG(sb.st_mode))
                        permission[0] = '-'; 	
                    if(sb.st_mode & S_IRUSR)
                        permission[1] = 'r'; 
                    else	
                        permission[1] = '-'; 	
                    if(sb.st_mode & S_IWUSR)
                        permission[2] = 'w';
                    else
                        permission[2] = '-';
                    if(sb.st_mode & S_IXUSR)
                        permission[3] = 'x';
                    else
                        permission[3] = '-';
                    if(sb.st_mode & S_IRGRP)
                        permission[4] = 'r';
                    else
                        permission[4] = '-';
                    if(sb.st_mode & S_IWGRP)
                        permission[5] = 'w';
                    else
                        permission[5] = '-';
                    if(sb.st_mode & S_IXGRP)
                        permission[6] = 'x';
                    else
                        permission[6] = '-';
                    if(sb.st_mode & S_IROTH)
                        permission[7] = 'r'; 
                    else
                        permission[7] = '-'; 
                    if(sb.st_mode & S_IWOTH)
                        permission[8] = 'w';
                    else
                        permission[8] = '-';
                    if(sb.st_mode & S_IXOTH)
                        permission[9] = 'x';
                    else
                        permission[9] = '-';
                    }

                    permission[10] = '\0';
                    printf("%s ",permission);
                    printf("  %ld %s %s", sb.st_nlink,getpwuid(sb.st_uid)->pw_name,getgrgid(sb.st_gid)->gr_name);
                    printf("%13ld ", sb.st_size);
                    // printf("%s %s\n", ctime(&(sb.st_mtime))+4,d->d_name);
                    struct tm dt;
                    dt = *(gmtime(&sb.st_ctime));
                    printf("%d-%d-%d  ", dt.tm_mday, dt.tm_mon, dt.tm_year + 2000);
                    printf("%s\n",d->d_name);
                    
                }
                    
            }
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
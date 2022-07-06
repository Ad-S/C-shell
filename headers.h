#include <stdio.h>    
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>
#include<string.h>
#include<signal.h>
#include<time.h>
#include<dirent.h>
#include<errno.h>
#include "background.h"
#include "inputgiven.h"
#include "foreground.h"
#include "cd.h"
#include "echo1.h"
#include "ls.h"
#include "prompt.h"
#include "pinfo.h"
#include "pwd.h"
#include "repeat.h"
#include "history.h"
#include "do_pipe.h"
#include "redirt.h"
#include "jobs.h"


char home_path[1024];
char oldpath[1024];
char allbgcmd[1000][1000];
char hist[1000][1000];
int histcmd;
int allbgpid[10000];
// int priyanshnoty ;
int noofbg ;
int run;

// #include "created_functions.h"
## OLD SPECIFICATIONS
### SPECIFICATION 1
1. Displaying username and hostname and the current directory is the home directory.

### SPECIFICATION 2
1. Implement cd as given in the assignemet.
2. echo and pwd are implemented .Extra spaces and tabs are handeled.

### SPECIFICATION 3
1. ls command with -a and -l flag is implemented.

### SPECIFICATION 4
1. Foreground and background processes are handeled. Built-in commands except ls, echo,cd, pwd, pinfo are handeled.

### SPECIFICATION 5
1. pinfo command prints the process-related info of your shell program. pinfo <.pid> is also handeled.

### SPECIFICATION 6
1. Finished Background Processes are handeled and if the background process exits then the shell displays the appropriate message to the
user.

### SPECIFICATION 7
1. Repeat is implemented.

### BONUS
1. history and history num is implemented.

## NEW SPECIFICATIONS

### Specification 1: Input/Output Redirection
1. Made a file called redirt.c in it according to the redirection changing my input and output file and then sending it to other commands which execute normally but uses the new input and output file to read and write.

### Specification 2: Command Pipelines
1. To handle piping I made pipe.c file which checks if piping is requiered and then in every command I use the new input and output file to read and write by using dup and dup2.

### Specification 3: I/O Redirection within Command Pipelines
1. I/O Redirection within Command Pipelines is handeled.

### Specification 4: User-defined Commands
1. I implemented jobs which will print all the running and stopped jobs along with their pid.
2. I implemented sig which sends the signal corresponding to signal number​ to that process(running process) {I used kill to execute it}.
3. I implemented fg which brings the running or stopped background job corresponding to ​job number​ to the foreground, and changes its state to ​running I used signal to implement it.
4. All user defined commands are in jobs.c file.

### Specification 5: Signal Handling
1. I implemented Ctrl + D and Ctrl + C as specified in the assignment pdf.


### NOTE
1. Global variables are defined in headers.h file.
2. Username and hostname are displayed by prompt.h.
3. In main.c the main while loop is running.
4. On giving exit as an input you will exit from the shell.

### COMPILE
1. MAKEFILE IS MADE FOR COMPILING ALL THE CODES WHICH IS STORED IN DIRECTORY OF SHELL CODES. SO TO COMPILE CODE JUST GO TO THE WORKING DIRECTORY OF SHELL CODES AND WRITE "make" COMMAND IN THE TERMINAL.
2. After compiling type ./a.out to execute.



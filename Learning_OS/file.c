#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{

    
    int fd = open("output.txt", O_CREAT | O_WRONLY| O_APPEND | 0644);
    // printf("%d", fd);
    if (fd < 0)
    {
        perror("File open failed");
        exit(1);
    }
    pid_t pid = fork();
     // parent
    if (pid > 0)
    {
        char msg[] = "-parent: This is written by parent process\n";
        int n = strlen(msg);
        write(fd, msg, n);
    }
    // child 
    if (pid == 0)
    {
        char msg[] = "-child: This is written by child process";
        int n = strlen(msg);
        write(fd, msg, n);
    }
    close(fd);
   
    return (0);
}

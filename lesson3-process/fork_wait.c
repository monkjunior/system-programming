#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    char *message;
    int n;
    printf("fork program starting\n");
    pid = fork();
    printf("%d\n", getpid());
    int exit_code;
    switch(pid)
    {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message = "This is the child";
            n = 30;
            exit_code =37;
            break;
        default:
            message = "This is the parent";
            n = 50;
            exit_code =0;
            break;
    }
    //The order of output is based on cpu schedule
    for(; n > 0; n--) {
        puts(message);
        sleep(1);
    }
    if (pid != 0) {
        int stat_val;
        pid_t child_pid;
        child_pid = wait(&stat_val);
        printf("Child has finished: PID = %d\n", child_pid);
        if(WIFEXITED(stat_val))
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        else
            printf("Child terminated abnormally\n");
        printf("Parent ended \n");
    }
    exit(exit_code);
}
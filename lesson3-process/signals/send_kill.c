#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

int main(){
    pid_t my_pid = getpid();
    for (int i=0; i<10; ++i){
        printf("Tien trinh %d dang chay\n", my_pid);
        sleep(1);
    }
    //Gui tin hieu SIGSTOP den tien trinh dang chay
    kill(my_pid, SIGSTOP);
    printf("Tien trinh se khong chay o day");
}
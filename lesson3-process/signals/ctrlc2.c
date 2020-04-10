#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int sig){
    // Now Ctr + C will print this without stopping process
    printf("OUCH - I got signal %d", sig);
    // Now we return back perrmission to system, Ctrl + C second time will stop process
    (void) signal(SIGINT, SIG_DFL);
}

int main(){
    struct  sigaction act;
    /*
    void (*) (int) sa_handler       /* function, SIG_DFL or SIG_IGN
    sigset_t sa_mask                * signals to block in sa_handler
    int sa_flags                    /* signal action modifiers
    */
    act.sa_handler = ouch;          //Point to handle function
    sigemptyset(&act.sa_mask);      //Now this is empty so it will not block any signal
    act.sa_flags = 0;
    sigaction(SIGINT, &act, 0);
    while(1) {
        printf("Hello World!\n");
        sleep(1);
    }   
}
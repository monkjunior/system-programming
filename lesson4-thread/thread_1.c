/* CREATE , RUN THEN JOIN A THREAD */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> //POSIX Thread Lib

// Declare the functin thread will call when you create it
void *thread_function(void *arg);

char message[] = "Hello World";

int main(){
    int res;
    pthread_t a_thread;
    void *thread_result;
    /* Create thread using pthead_create(...)
    **      a_thread    : thread identifier
    **      NULL        : dont modify default thread attributes
    **      thread_function
    **      message
    */
    res = pthread_create(&a_thread, NULL, thread_function, (void *)message);

    // The original thread checks that the new thread has started and then calls pthread_join
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    /* Here you pass the identifier of the thread that you are waiting to join and a pointer to a result.
    ** This function will wait until the other thread terminates before it returns.
    ** MAKE THREAD FUNCTION DONE BEFORE RUN CODES BELOW
    ** In constrast to pthread_join(), use pthread_detach() to detach thread.
    ** Then thread will auto clean it resources when task is done.
    */
    printf("Waiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);

    // It then prints the return value from the thread and the contents of a variable, and exits.
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined, it returned %s\n", (char *)thread_result);
    printf("Message is now %s\n", message);
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    printf("thread_function is running. Argument was %s\n", (char *)arg);
    sleep(3);
    strcpy(message, "Bye!");
    pthread_exit("Thank you for the CPU time");
}

/* Compile CMD
**  gcc -o 1.SimpleThreadedProgram 1.SimpleThreadedProgram.c -pthread
*/
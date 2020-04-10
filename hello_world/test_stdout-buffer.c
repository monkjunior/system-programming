#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int time = 0;
    while (time++ < 5)
    {
        printf("%d\n", time);
        sleep(1);
    }
    printf("Done\n");
    return 0;
}
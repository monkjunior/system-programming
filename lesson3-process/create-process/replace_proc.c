#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Running ps with execlp\n");
    execlp("cat", "cat", "/proc/cpuinfo", 0);
    printf("Done.\n"); // Now this will not be printed anymore
    exit(0);
}
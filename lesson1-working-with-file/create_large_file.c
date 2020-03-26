#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    char block[1048576];
    int large_file_out = open("large_file.txt", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    unsigned long int i;
    for (i = 0; i < 1048576; ++i){
        block[i] = '1';
    }
    for (i = 0; i < 1024; ++i){
        write(large_file_out, block, 1048576);
    }
    exit(0);
}
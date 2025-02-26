#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h> 

// #define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    // char cmd[BUFSIZE] = "wc -c < ";
    // strcat(cmd, argv[1]);
    // system(cmd);

    struct stat info;
    if (stat(argv[1], &info) != 0) {
        fprintf(stderr, "can't find file %s.\n", argv[1]);
        return -1;
    }

    printf("%ld\n", info.st_size);
    return 0;
}

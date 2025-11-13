#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//printing contents of one or more files.

int main(int argc, char *argv[]) {
    if (argc == 1) {
        return 0;  
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("cannot open file\n");
            exit(1);
        }

        char buffer[1024];

        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }

        fclose(fp);
    }

    return 0;
}
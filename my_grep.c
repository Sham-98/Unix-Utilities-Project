#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// print lines that contain a given search term.

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my-grep: searchterm [file ...]\n");
        return 1; 
    }


    
char *pattern = argv[1];

for (int i = 2; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
        printf("cannot open file: %s\n", argv[i]);
        continue;
    }

char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) {
            printf("%s: %s", argv[i], line); 
        }
    }
    fclose(fp);
}

    return 0;
}
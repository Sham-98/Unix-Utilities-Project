#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//compress files using run-length encoding (RLE).

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
        return 1;  
    }

    for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("my_zip: cannot open file %s\n", argv[i]);
            exit(1);
        }

    int count = 0;
    int curr, prev;

    prev = fgetc(fp);
    if (prev == EOF){
        fclose(fp);
        continue;
    }

    count = 1;
    while ((curr= fgetc(fp)) != EOF){
        if (curr == prev){
            count++;

    }   else {
            fwrite(&count, sizeof(int), 1, stdout);
            fputc(prev, stdout);
            prev = curr;
            count = 1;
        }
    }
    fwrite(&count, sizeof(int), 1, stdout);
    fputc(prev, stdout);
    fclose(fp);
    }
return 0;
}
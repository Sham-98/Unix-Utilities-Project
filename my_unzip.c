#include <stdio.h>
#include <stdlib.h>


//read binary RLE file and restore the original text.

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my_unzip: file1\n");
        return 1; 
    }



for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "rb");
        if (fp == NULL) {
            printf("my_unzip: cannot open file %s\n", argv[i]);
            exit(1);
        }

int count;
char ch;


        while (fread(&count, sizeof(int), 1, fp) == 1) {
            fread(&ch, sizeof(char), 1, fp);
            for (int j = 0; j < count; j++)
                printf("%c", ch);
        }

        fclose(fp);
    }

    return 0;
}
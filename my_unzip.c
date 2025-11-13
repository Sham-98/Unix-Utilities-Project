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
unsigned char c;

        while (fread(&count, sizeof(int), 1, fp) == 1) {
            if (fread(&c, sizeof(unsigned char), 1, fp) != 1) {
                break;
            }

            for (int j = 0; j < count; j++) {
                putchar(c);
            }
        }

        fclose(fp);
    }

    return 0;
}
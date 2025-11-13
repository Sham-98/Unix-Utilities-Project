#include <stdio.h>
#include <stdlib.h>


//compress files using run-length encoding (RLE).

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my_zip: file1 [file2 ...]\n");
        return 1;  
    }

        for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("my_zip: cannot open file\n");
            return 1;
        }

        int count = 0;
        int curr = fgetc(fp);
        if (curr == EOF) {
            fclose(fp);
            continue;
        }

        while (curr != EOF) {
            int next = fgetc(fp);
            count = 1;

            while (next == curr && next != EOF) {
                count++;
                next = fgetc(fp);
            }

            fwrite(&count, sizeof(int), 1, stdout);
            fwrite(&curr, sizeof(char), 1, stdout);
            curr = next;
        }

        fclose(fp);
    }

    return 0;
}
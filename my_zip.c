#include <stdio.h>
#include <stdlib.h>


//compress files using run-length encoding (RLE).

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
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

    if (curr == EOF){
        fclose(fp);
        continue;
    }

    while (1){
        int next = fgetc(fp);
            count++;

            if (next != curr) {
                fwrite(&count, sizeof(int), 1, stdout);  // 4 bytes
                fwrite(&curr, sizeof(char), 1, stdout); // 1 byte
                count = 0;
                curr = next;
            }

            if (next == EOF) break;
        }
    fclose(fp);
    }
return 0;
}
/*
Q124: Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().

Sample Test Cases:
Input 1:
Source File: source.txt (Content: Learning C File Handling)
Output 1:
File copied successfully to destination.txt
*/

#include <stdio.h>

int main(void) {
    char src[260], dst[260];
    if (scanf("%259s %259s", src, dst) != 2) return 0;

    FILE *in = fopen(src, "r");
    if (in == NULL) {
        printf("Error: Could not open source file %s\n", src);
        return 1;
    }

    FILE *out = fopen(dst, "w");
    if (out == NULL) {
        fclose(in);
        printf("Error: Could not create destination file %s\n", dst);
        return 1;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);
    printf("File copied successfully to %s\n", dst);
    return 0;
}

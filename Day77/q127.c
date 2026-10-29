/*
Q127: Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.

Sample Test Cases:
Input 1:
Input File (input.txt): Hello World\nC programming
Output 1:
Output File (output.txt): HELLO WORLD\nC PROGRAMMING
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Error: Could not open input.txt\n");
        return 1;
    }

    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        fclose(in);
        printf("Error: Could not create output.txt\n");
        return 1;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(toupper((unsigned char)ch), out);
    }

    fclose(in);
    fclose(out);
    return 0;
}

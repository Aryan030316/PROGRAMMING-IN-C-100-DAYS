/*
Q125: Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.

Sample Test Cases:
Input 1:
Existing File: data.txt (Content before execution: Hello world)
User Input: This is appended text.
Output 1:
File updated successfully with appended text.
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char line[1024];
    if (!fgets(line, sizeof(line), stdin)) return 0;

    size_t len = strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
        line[--len] = '\0';
    }

    FILE *fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("Error: Could not open data.txt\n");
        return 1;
    }

    fprintf(fp, "\n%s", line);
    fclose(fp);

    printf("File updated successfully with appended text.\n");
    return 0;
}

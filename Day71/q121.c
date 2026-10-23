/*
Q121: Write a C program that creates a text file named info.txt in write mode. The program should take the user’s name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.

Sample Test Cases:
Input 1:
Name: Rahul, Age: 23
Output 1:
File created successfully! Data written to info.txt
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char name[200];
    int age = 0;
    char line[500];
    if (!fgets(line, sizeof(line), stdin)) return 0;

    if (sscanf(line, "Name: %199[^,], Age: %d", name, &age) != 2 &&
        sscanf(line, "%199s %d", name, &age) != 2) {
        return 0;
    }

    FILE *fp = fopen("info.txt", "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    fprintf(fp, "Name: %s\nAge: %d\n", name, age);
    fclose(fp);

    printf("File created successfully! Data written to info.txt\n");
    return 0;
}

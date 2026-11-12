/*
Q141: Define a structure Student with name, roll_no, and marks, then read and print one student's data.

Sample Test Cases:
Input 1:
Name: Asha
Roll: 101
Marks: 90
Output 1:
Name: Asha | Roll: 101 | Marks: 90
*/

#include <stdio.h>
#include <string.h>

struct Student {
    char name[100];
    int roll_no;
    int marks;
};

int main(void) {
    struct Student s;
    char buf[512];
    size_t len = fread(buf, 1, sizeof(buf) - 1, stdin);
    buf[len] = '\0';

    if (sscanf(buf, "Name: %99s Roll: %d Marks: %d", s.name, &s.roll_no, &s.marks) == 3 ||
        sscanf(buf, "%99s %d %d", s.name, &s.roll_no, &s.marks) == 3) {
        printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll_no, s.marks);
    }
    return 0;
}

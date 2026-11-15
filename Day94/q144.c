/*
Q144: Write a function that accepts a structure as parameter and prints its members.

Sample Test Cases:
Input 1:
Student: Neha 104 92
Output 1:
Name: Neha | Roll: 104 | Marks: 92
*/

#include <stdio.h>

struct Student {
    char name[100];
    int roll_no;
    int marks;
};

static void print_student(struct Student s) {
    printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll_no, s.marks);
}

int main(void) {
    char buf[256];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    struct Student s;
    if (sscanf(buf, "Student: %99s %d %d", s.name, &s.roll_no, &s.marks) == 3 ||
        sscanf(buf, "%99s %d %d", s.name, &s.roll_no, &s.marks) == 3) {
        print_student(s);
    }
    return 0;
}

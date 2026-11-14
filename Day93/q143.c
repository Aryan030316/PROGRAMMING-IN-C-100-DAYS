/*
Q143: Find and print the student with the highest marks.

Sample Test Cases:
Input 1:
3 students: Ravi 101 95, Sita 102 85, Aman 103 88
Output 1:
Topper: Ravi (Marks: 95)
*/

#include <stdio.h>
#include <string.h>

struct Student {
    char name[100];
    int roll_no;
    int marks;
};

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    char peek[32];
    if (scanf(" %31s", peek) != 1) return 0;

    struct Student top = {"", 0, -1};
    for (int i = 0; i < n; i++) {
        struct Student cur;
        if (i == 0 && strcmp(peek, "students:") != 0) {
            strncpy(cur.name, peek, sizeof(cur.name) - 1);
            cur.name[sizeof(cur.name) - 1] = '\0';
            if (scanf("%d %d", &cur.roll_no, &cur.marks) != 2) break;
        } else {
            if (scanf(" ,%99s %d %d", cur.name, &cur.roll_no, &cur.marks) != 3 &&
                scanf(" %99s %d %d", cur.name, &cur.roll_no, &cur.marks) != 3) {
                break;
            }
        }
        scanf(" ,");
        if (i == 0 || cur.marks > top.marks) {
            top = cur;
        }
    }
    printf("Topper: %s (Marks: %d)\n", top.name, top.marks);
    return 0;
}

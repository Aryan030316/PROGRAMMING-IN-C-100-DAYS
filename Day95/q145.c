/*
Q145: Return a structure containing top student's details from a function.

Sample Test Cases:
Input 1:
3 students: Riya 101 89, Karan 102 96, Meena 103 92
Output 1:
Top Student: Karan | Roll: 102 | Marks: 96
*/

#include <stdio.h>
#include <string.h>

struct Student {
    char name[100];
    int roll_no;
    int marks;
};

static struct Student find_top_student(const struct Student *arr, int n) {
    struct Student best = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i].marks > best.marks) {
            best = arr[i];
        }
    }
    return best;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) return 0;

    char peek[32];
    if (scanf(" %31s", peek) != 1) return 0;

    struct Student students[100];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 && strcmp(peek, "students:") != 0) {
            strncpy(students[i].name, peek, sizeof(students[i].name) - 1);
            students[i].name[sizeof(students[i].name) - 1] = '\0';
            if (scanf("%d %d", &students[i].roll_no, &students[i].marks) != 2) break;
        } else {
            if (scanf(" ,%99s %d %d", students[i].name, &students[i].roll_no, &students[i].marks) != 3 &&
                scanf(" %99s %d %d", students[i].name, &students[i].roll_no, &students[i].marks) != 3) {
                break;
            }
        }
        scanf(" ,");
        count++;
    }
    if (count == 0) return 0;

    struct Student top = find_top_student(students, count);
    printf("Top Student: %s | Roll: %d | Marks: %d\n", top.name, top.roll_no, top.marks);
    return 0;
}

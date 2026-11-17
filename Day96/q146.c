/*
Q146: Create Employee structure with nested Date structure for joining date and print details.

Sample Test Cases:
Input 1:
Employee: Raj | ID: 11 | Joining Date: 12 05 2020
Output 1:
Name: Raj | ID: 11 | Joining Date: 12/05/2020
*/

#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[100];
    int id;
    struct Date joining_date;
};

int main(void) {
    char buf[256];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    struct Employee e;
    if (sscanf(buf, "Employee: %99s | ID: %d | Joining Date: %d %d %d",
               e.name, &e.id, &e.joining_date.day, &e.joining_date.month, &e.joining_date.year) == 5 ||
        sscanf(buf, "%99s %d %d %d %d",
               e.name, &e.id, &e.joining_date.day, &e.joining_date.month, &e.joining_date.year) == 5) {
        printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n",
               e.name, e.id, e.joining_date.day, e.joining_date.month, e.joining_date.year);
    }
    return 0;
}

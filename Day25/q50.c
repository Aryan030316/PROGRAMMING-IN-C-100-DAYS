/*
Q50: Write a program to print the following pattern:
*****
 ****
  ***
   **
    *

Sample Test Cases:
Input 1:

Output 1:
*****
 ****
  ***
   **
    *
*/

#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        for (int s = 0; s < i; s++) {
            printf(" ");
        }
        for (int j = 0; j < 5 - i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

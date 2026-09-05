/*
Q54: Write a program to print the following pattern:

   *
  ***
 *****
*******
 *****
  ***
   *

Sample Test Cases:
Input 1:

Output 1:
Pattern with layers of stars as shown.
*/

#include <stdio.h>

int main() {
    int stars[]  = {1, 3, 5, 7, 5, 3, 1};
    int spaces[] = {3, 2, 1, 0, 1, 2, 3};
    for (int i = 0; i < 7; i++) {
        for (int s = 0; s < spaces[i]; s++) {
            printf(" ");
        }
        for (int j = 0; j < stars[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

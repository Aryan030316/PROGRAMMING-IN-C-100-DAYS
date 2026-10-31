/*
Q129: A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.

Sample Test Cases:
Input 1:
File: numbers.txt (Content: 10 20 30 40 50)
Output 1:
Sum = 150
Average = 30.00
*/

#include <stdio.h>

int main(void) {
    FILE *fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open numbers.txt\n");
        return 1;
    }

    long long sum = 0;
    int val, count = 0;
    while (fscanf(fp, "%d", &val) == 1) {
        sum += val;
        count++;
    }
    fclose(fp);

    double avg = (count > 0) ? (double)sum / count : 0.0;
    printf("Sum = %lld\nAverage = %.2f\n", sum, avg);
    return 0;
}

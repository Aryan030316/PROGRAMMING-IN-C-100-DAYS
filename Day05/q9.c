/*
Q9: Write a program to calculate simple and compound interest for given principal, rate, and time.

Sample Test Cases:
Input 1:
1000 5 2
Output 1:
Simple Interest=100, Compound Interest=102.5

Input 2:
5000 7 3
Output 2:
Simple Interest=1050, Compound Interest=1125.76
*/

#include <stdio.h>
#include <math.h>

int main() {
    double p, r, t;
    if (scanf("%lf %lf %lf", &p, &r, &t) == 3) {
        double si = (p * r * t) / 100.0;
        double ci = p * pow(1.0 + r / 100.0, t) - p;
        if (si == (long long)si)
            printf("Simple Interest=%lld, ", (long long)si);
        else
            printf("Simple Interest=%.2f, ", si);

        if (ci == (long long)ci)
            printf("Compound Interest=%lld\n", (long long)ci);
        else
            printf("Compound Interest=%.2f\n", ci);
    }
    return 0;
}

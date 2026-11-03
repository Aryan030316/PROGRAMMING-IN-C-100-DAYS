/*
Q132: Define an enum for traffic lights (RED, YELLOW, GREEN) and print 'Stop', 'Wait', or 'Go' based on its value.

Sample Test Cases:
Input 1:
GREEN
Output 1:
Go
*/

#include <stdio.h>
#include <string.h>

enum TrafficLight { RED, YELLOW, GREEN };

int main(void) {
    char tok[32];
    if (scanf("%31s", tok) != 1) return 0;

    enum TrafficLight light;
    if (strcmp(tok, "RED") == 0 || strcmp(tok, "0") == 0) light = RED;
    else if (strcmp(tok, "YELLOW") == 0 || strcmp(tok, "1") == 0) light = YELLOW;
    else if (strcmp(tok, "GREEN") == 0 || strcmp(tok, "2") == 0) light = GREEN;
    else return 0;

    switch (light) {
        case RED: printf("Stop\n"); break;
        case YELLOW: printf("Wait\n"); break;
        case GREEN: printf("Go\n"); break;
    }
    return 0;
}

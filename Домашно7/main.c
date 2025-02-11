#include <stdio.h>
#include "quadraticroots.h"

int main() {
    QuadraticRootsResult res1 = findroots(1, -6, 5);
    if (res1.norealroots) {
        printf("No real roots!\n");
    } else {
        printf("Roots are: x1 = %.2Lf, x2 = %.2Lf\n", res1.x1, res1.x2);
    }

    QuadraticRootsResult res2 = findroots(1.5f, 4.0f, 2.0f);
    if (res2.norealroots) {
        printf("No real roots!\n");
    } else {
        printf("Roots are: x1 = %.2Lf, x2 = %.2Lf\n", res2.x1, res2.x2);
    }

    QuadraticRootsResult res3 = findroots(2.0, -3.0, -14.0);
    if (res3.norealroots) {
        printf("No real roots!\n");
    } else {
        printf("Roots are: x1 = %.2Lf, x2 = %.2Lf\n", res3.x1, res3.x2);
    }

    return 0;
}

#include <stdio.h>
int nod(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int nok(int a, int b) {
    return (a * b) / nod(a, b);
}

int main() {
    int a, b;
    printf("Въведете две числа: ");
    scanf("%d  ", &a);
    scanf("%d", &b);
    int result = nok(a, b);
    printf("Най-малкото общо кратно на %d и %d е: %d\n", a, b, result);
    return 0;
}

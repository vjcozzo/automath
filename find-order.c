#include <stdio.h>
#include <stdlib.h>

static int gcd(int a, int b);

static int gcd(int x, int y) {
    if (x > y) {
        int r1 = x;
        int r2 = y;
        while (r2 > 0) {
            int t = r2;
            r2 = (r1 % r2);
            r1 = t;
        }
        return r1;
    } else {
        int r1 = y;
        int r2 = x;
        while (r2 > 0) {
            int t = r2;
            r2 = (r1 % r2);
            r1 = t;
        }
        return r1;
    }
}

int main(int argc, char **argv) {
    int m, a, g, runningPow, exp;
    printf("Please enter the modulus: ");
    scanf("%d", &m);
    printf("Please enter a number coprime: ");
    scanf("%d", &a);
    g = gcd(a, m);
    if (g != 1) {
        printf("The integers are evidently not coprime.\n");
        printf("gcd(%d, %d) = %d\n", a, m, g);
        exit(0);
    }
    a %= m;
    runningPow = a;
    exp = 1;
    while (runningPow != 1) {
        runningPow *= a;
        runningPow %= m;
        exp ++;
    }
    printf("The order of %d (mod %d) equals %d\n", a, m, exp);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LIMIT 500

int main(int argc, char * argv[])
{
    double s = 1.0;
    double n = 3.0;

    double s2 = s / 2.0;
    double a  = sqrt(1.0 - s2 * s2);
    double b  = 1 - a;

    for (int i = 0; i < LIMIT; i++) {
        s  = sqrt(s2 * s2 + b * b);
        n  = n * 2;
        s2 = s / 2.0;
        a  = sqrt(1.0 - s2 * s2);
        b  = 1 - a;
    }

    printf("%s@%d\t%0.20lf\n", argv[0], LIMIT, s * n);
    printf("s = %0.20lf\n", s);
    printf("n = %0.0lf\n", n);
}

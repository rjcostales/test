#include <stdio.h>
#include <time.h>
#include <math.h>
#include <locale.h>

#define LIMIT 1000000
#ifndef M_PI
# define M_PI 3.14159265358979323846264338327950288
#endif

typedef double real;

int main(int argc, char *argv[])
{
    real area  = 0.0;
    real delta = M_PI / LIMIT;

    clock_t start, stop;

    start = clock();
    for (register int i = 0; i < LIMIT; i++) {
        real x = i * delta + delta / 2.0;
        real y = sin(x);

        area += y * delta;
    }
    stop = clock();

    setlocale(LC_NUMERIC, "");
    printf("execution time: %0.6f secs.\t",
      (float) (stop - start) / (float) CLOCKS_PER_SEC);
    printf("%s\t%'d\t%'0.20f\n", argv[0], LIMIT, area);
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main()
{
    int a = INT_MAX;
    unsigned short int b = USHRT_MAX;
    signed long int c = LONG_MAX;
    float d = FLT_MAX;
    double e = DBL_MAX;

    printf("integer,\tMax Value: %d,\tSize: %d\n", a,sizeof(a));
    printf("unsigned short integer,\tMax Value: %d,\tSize: %d\n", b, sizeof(b));
    printf("signed long int,\tMax Value: %ld,\tSize: %d\n", c, sizeof(c));
    printf("float,\tMax Value: %f,\tSize: %d\n", d, sizeof(d));
    printf("double,\tMax Value: %f,\tSize: %d\n", e, sizeof(e));
    return 0;
}

#include <stdio.h>

int main()
{
    printf("%d\n", 5 * 3);
    // truncates due to type difference
    printf("%d\n", 5 / 3);

    float x = 8.3;
    double y = 15.53;

    printf("%f %lf\n", x, y);
    float a = 5.0;
    printf("%f\n", a / 3.0);

    int b = 5;
    // implicit conversion of b in the calculation of b / 3.0;
    printf("%f\n", b / 3.0);

    int c = 3;
    // explicity type conversion (casting)
    printf("%f\n", (float)b / c);
    // below give an type error
    // printf("%f\n", b / c);

    // float point minimization double type better than float in precision but does not solve the problem of this error

    return 0;
}
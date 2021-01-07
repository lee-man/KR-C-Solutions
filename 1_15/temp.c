#include <stdio.h>

float FtoC(int celsius);

int main(void) {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = FtoC(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

float FtoC(int fahr)
{
    return 5.0 / 9.0 * (fahr - 32.0);
}

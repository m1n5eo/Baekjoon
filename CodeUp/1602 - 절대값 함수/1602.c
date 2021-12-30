#include <stdio.h>

double ABS(double input) {
    if (input < 0)
        input = -input;
    return input;
}

int main() {
    double n;
    scanf("%lf", &n);
    printf("%.10g", ABS(n));
}
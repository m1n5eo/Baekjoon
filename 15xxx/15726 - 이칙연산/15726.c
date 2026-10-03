#include <stdio.h>
#include <math.h>

int main() {
    double arr[3];

    scanf("%lf %lf %lf", &arr[0], &arr[1], &arr[2]);

    if(arr[1] > arr[2]) {
        printf("%.0lf", floor(arr[0]*arr[1]/arr[2]));
    }
    else {
        printf("%.0lf", floor(arr[0]/arr[1]*arr[2]));
    }

    return 0;
}
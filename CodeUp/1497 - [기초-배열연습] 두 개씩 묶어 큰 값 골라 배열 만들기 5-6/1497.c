#include <stdio.h>

int main() {
    int n, arr[102], max = -33333;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for(int i = 0; i < n; i++) {
        if(i % 2 != 0) {
            if(max < arr[i]) max = arr[i];
            printf("%d ", max);
            max = -33333;
        }
        else if(max < arr[i]) max = arr[i];
    }
}
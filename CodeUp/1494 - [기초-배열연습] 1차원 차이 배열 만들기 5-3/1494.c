#include <stdio.h>

int arr[102];

int main() {
    int k, n, s, e, u, sum = 0;
    scanf("%d %d", &k, &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d %d %d", &s, &e, &u);
        arr[s] = arr[s] + u;
        arr[e+1] = arr[e+1] - u;
    }

    for(int i = 1; i <= k; i++) {
        printf("%d ", arr[i]);
        sum = sum + arr[i];
        arr[i] = sum;
    }
    printf("\n");

    for(int i = 1; i <= k; i++) {
        printf("%d ", arr[i]);
    }
}
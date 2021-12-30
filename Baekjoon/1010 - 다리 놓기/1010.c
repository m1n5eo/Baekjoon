#include <stdio.h>

int arr[31][31];

int main() {
    for(int i = 1; i <= 30; i++) arr[1][i] = i;
    for(int i = 2; i <= 30; i++) {
        for(int j = 1; j <= 30; j++) {
            arr[i][j] = arr[i-1][j-1]+arr[i][j-1];
        }
    }

    int t, n, m;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        printf("%d\n", arr[n][m]);
    }
}
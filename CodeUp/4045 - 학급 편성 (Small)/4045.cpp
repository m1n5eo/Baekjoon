#include <bits/stdc++.h>
using namespace std;

int arr[51][51];

int main() {
    int n, m;
    scanf("%d %d", &n ,&m);
    for(int i = 1; i <= n; i++) {
        arr[i][1] = 1;
        arr[i][i] = 1;
    }
    arr[2][2] = arr[3][2] = 1;

    for(int i = 4; i <= n; i++) {
        for(int j = 2; j < i; j++) {
            int u=i-j;
            for(int k=1; k<=j; k++){
            arr[i][j] = arr[i][j] + arr[u][k];
            }
        }
    }

    /*for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }*/

    int sum = 0;
    for(int i = 1; i <= m; i++) sum = sum + arr[n][i];
    printf("%d", sum);
}
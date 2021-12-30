#include <bits/stdc++.h>
using namespace std;

int arr[5003][5003];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        arr[i][1] = 1;
    }
    arr[2][2] = arr[3][2] = 2;
    arr[3][3] = 3;
    for(int i = 4; i <= n; i++) {
        for(int j = 2; j <= i; j++) {
            int u = i-j;
            if(arr[u][j] == 0) arr[i][j] = (arr[u][u] + arr[i][j-1]) % 123456789;
            else arr[i][j] = (arr[u][j] + arr[i][j-1]) % 123456789;
            if(i == j) arr[i][j]++;
        }
    }

    /*for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }*/

    printf("%d", arr[n][m]);
}
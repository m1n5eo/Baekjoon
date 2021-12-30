#include <bits/stdc++.h>
using namespace std;

#define mod 1000000000

int arr[101][11];

int main() {
    int n, sum = 0;
    scanf("%d", &n);

    for(int i = 0; i < 10; i++) arr[1][i] = 1;
    arr[1][10] = 0;

    for(int i = 2; i <= n; i++) {
        arr[i][10] = 0;
        arr[i][0] = arr[i-1][1];
        for(int j = 1; j <= 9; j++) {
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % mod;
        }
    }

    for(int i = 1; i <= 9; i++) {
        sum = (sum + arr[n][i])%mod;
    }
    printf("%d", sum);
}

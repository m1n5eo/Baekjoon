#include <bits/stdc++.h>

using namespace std;

int arr[33][33];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        arr[i][i] = 1;
        arr[i][1] = i;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(arr[i][j] == 0) {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }
    printf("%d", arr[n][k]);
}
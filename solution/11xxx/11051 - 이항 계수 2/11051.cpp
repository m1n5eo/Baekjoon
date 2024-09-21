#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];

void setting() {
    for(int i = 1; i <= 1000; i++) {
        arr[i][0] = 1; arr[i][i] = 1;
    }
    for(int i = 2; i <= 1000; i++) {
        for(int j = 1; j < i; j++) {
            arr[i][j] = (arr[i-1][j-1]+arr[i-1][j])%10007;
        }
    }
}

int main() {
    setting();
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", arr[n][k]);
}

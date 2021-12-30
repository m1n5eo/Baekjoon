#include <bits/stdc++.h>
using namespace std;

int n, r;
int arr[33][33];

void f(int a, int b) {
    arr[a][a] = 1;
    arr[a][b] = arr[a-1][b-1]+arr[a-1][b];
    if(a > n) return;
    f(a+1, b+1);
    if(b == 0) f(a+1, b);
}

int main() {
    scanf("%d %d", &n, &r);
    arr[0][0] = 1; arr[0][1] = 0;
    f(1, 0);
    printf("%d", arr[n][r]);
}
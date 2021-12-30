#include <bits/stdc++.h>
using namespace std;

int n, m, arr[22], cnt = 0;

void f(int num, int i, int plmi, int sum) {
    if(i > m) {
        if(sum == n) cnt = cnt + 1;
        return;
    }

    f(arr[i+1], i+1, 1, sum+arr[i]);
    f(arr[i+1], i+1, 0, sum-arr[i]);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) scanf("%d", &arr[i]);
    f(arr[1], 1, 1, 0);
    printf("%d", cnt);
}
#include <bits/stdc++.h>
using namespace std;

int n, s, cnt = 0;
int arr[22];

void f(int idx, int sum) {
    sum = sum+arr[idx];
    if (idx >= n) return;
    else if (sum == s) cnt++;

    f(idx+1, sum);
    f(idx+1, sum-arr[idx]);
}

int main() {
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    f(0, 0);
    printf("%d", cnt);
}
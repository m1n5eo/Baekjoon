#include <bits/stdc++.h>
using namespace std;

int n, s, cnt = 0, sum, arr[22];

void f(int idx, int sum) {
    if(s == sum) {
        cnt = cnt + 1;

    }
    for(int i = idx; i < n; i++) {
        f(i+1, sum+arr[i]);
    }
}

int main() {
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    f(0, 0);
    if(s == 0) cnt = cnt - 1;
    printf("%d", cnt);
}
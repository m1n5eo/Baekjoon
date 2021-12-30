#include <bits/stdc++.h>
using namespace std;

int n, a, b, m, minn = 2100000000;
int cnt = 0, arr[22];

void f(int idx, int o1, int o2) {
    if(idx == m) {
        if(cnt < minn) minn = cnt;
        return;
    }
    cnt = cnt + abs(o1-arr[idx]);
    f(idx+1, arr[idx], o2);
    cnt = cnt - abs(o1-arr[idx]);

    cnt = cnt + abs(o2-arr[idx]);
    f(idx+1, o1, arr[idx]);
    cnt = cnt - abs(o2-arr[idx]);

    return;
}

int main() {
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }
    f(0, a, b);
    printf("%d", minn);
}
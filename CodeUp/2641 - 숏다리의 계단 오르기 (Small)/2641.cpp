#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;

void f(int k, int s,int r) {
    if(s == n) {
        cnt = cnt + 1;
        return;
    }
    if(s > n) return;
    if(k > 0) {
        f(k-1, s+1,1);
        f(k-1, s+2,2);
    }
    else {
        f(0, s+1,1);
        f(0, s+2,2);
        f(2, s+3,3);
    }
}

int main() {
    scanf("%d", &n);
    f(0, 0, 1);
    printf("%d", cnt);
}
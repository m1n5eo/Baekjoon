#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;
int arr[11];

void f(int nidx, int kidx, int sw) { /// sw0.안칠함   sw1.칠함
    if(nidx == n && kidx == k) {
        cnt++;
        return;
    }
    else if(nidx > n) return;

    if(sw == 1) f(nidx+1, kidx, 0);
    else if(sw == 0) {
        f(nidx+arr[kidx], kidx+1, 1);
        f(nidx+1, kidx, 0);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &arr[i]);
    }
    f(0, 0, 0);
    printf("%d", cnt);
}
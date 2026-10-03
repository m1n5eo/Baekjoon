#include <bits/stdc++.h>
using namespace std;

int n, dap, arr[16];

int chk(int k) {
    for(int i = 0; i < k; i++) {
        if(arr[k] == arr[i] || abs(arr[k]-arr[i]) == abs(k-i)) return 0;
    }
    return 1;
}

void f(int cnt) {
    if(cnt == n) {
        dap++;
        return;
    }
    else {
        for(int i = 0; i < n; i++) {
            arr[cnt] = i;
            if(chk(cnt) == 1) {
                f(cnt+1);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    f(0);
    printf("%d", dap);
}

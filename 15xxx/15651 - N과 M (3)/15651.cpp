#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9], chk[9];

void f(int idx) {
    if(idx == m) {
        for(int i = 0; i < m; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++) {
            arr[idx] = i;
            f(idx+1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    f(0);
}

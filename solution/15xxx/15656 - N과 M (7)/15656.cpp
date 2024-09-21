#include <bits/stdc++.h>
using namespace std;

int n, m;
int lst[9], arr[9], chk[9];

void f(int idx) {
    if(idx == m) {
        for(int i = 0; i < m; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++) {
        arr[idx] = lst[i];
        f(idx+1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &lst[i]);
    sort(lst+1, lst+n+1);
    f(0);
}

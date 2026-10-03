#include <bits/stdc++.h>
using namespace std;

int n, m;
int lst[9], arr[9], chk[10001];

void f(int idx) {
    if(idx == m) {
        for(int i = 0; i < m; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(chk[lst[i]] == 0) {
            chk[lst[i]] = 1;
            arr[idx] = lst[i];
            f(idx+1);
            chk[lst[i]] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &lst[i]);
    sort(lst+1, lst+n+1);
    f(0);
}

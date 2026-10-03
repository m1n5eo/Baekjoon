#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9], chk[9];

void f(int idx, int last) {
    if(idx == m) {
        for(int i = 0; i < m; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for(int i = last; i <= n; i++) {
        arr[idx] = i;
        f(idx+1, i);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    f(0, 1);
}

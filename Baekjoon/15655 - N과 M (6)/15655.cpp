#include <bits/stdc++.h>
using namespace std;

int n, m;
int listt[9], arr[9], chk[10001];

void f(int idx) {
    if(idx == m) {
        int cnt = 0, maxx = -1234567890;
        for(int i = 0; i < m; i++) {
            if(maxx < arr[i]) {
                maxx = arr[i];
                cnt++;
            }
        }
        if(cnt == m) {
            for(int i = 0; i < m; i++) printf("%d ", arr[i]);
            printf("\n");
        }
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(chk[listt[i]] == 0) {
            chk[listt[i]] = 1;
            arr[idx] = listt[i];
            f(idx+1);
            chk[listt[i]] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &listt[i]);
    sort(listt+1, listt+n+1);
    f(0);
}

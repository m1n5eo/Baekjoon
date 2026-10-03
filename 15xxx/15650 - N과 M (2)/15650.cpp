#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9], chk[9];

void f(int idx) {
    if(idx == m) {
        /*for(int i = 0; i < m; i++) printf("%d ", arr[i]);
        printf("\n");*/
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
        if(chk[i] == 0) {
            chk[i] = 1;
            arr[idx] = i;
            f(idx+1);
            chk[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    f(0);
}
#include <bits/stdc++.h>
using namespace std;

int n, m, f_n;
int lst[9], f_lst[9], arr[9], arr_idx[9], su[10001], chk[10001];

void f(int idx) {
    if(idx == m) {
        int cnt = 0, cntt = 0, maxx = -1234567890;
        for(int i = 0; i < m; i++) {
            if(su[arr[i]] >= chk[arr[i]]) cnt++;
        }
        if(cnt == m) {
            for(int i = 0; i < m; i++) printf("%d ", arr[i]);
            printf("\n");
        }
        return;
    }
    for(int i = 1; i <= f_n; i++) {
        arr_idx[idx] = i;
        arr[idx] = f_lst[i];
        chk[f_lst[i]]++;
        f(idx+1);
        chk[f_lst[i]]--;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    f_n = 1;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &lst[i]);
        if(su[lst[i]] == 0) {
            f_lst[f_n] = lst[i];
            su[lst[i]]++;
            f_n++;
        }
        else su[lst[i]]++;
    }
    /*for(int i = 1; i <= 10; i++) printf("%d", su[i]);
    printf("\n");*/
    f_n-=1;
    sort(lst+1, lst+n+1);
    sort(f_lst+1, f_lst+f_n+1);
    f(0);
}

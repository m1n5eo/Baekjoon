#include <bits/stdc++.h>

using namespace std;

int com, arr[103][103], visit[103];

void dfs(int n) {
    visit[n] = 1;
    for(int i = 1; i <= com; i++) {
        if(visit[i] == 0 && arr[n][i] == 1) {
            dfs(i);
        }
    }
}

int main() {
    int t, a, b, cnt = 0;
    scanf("%d %d", &com, &t);
    for(int i = 1; i <= t; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    dfs(1);
    for(int i = 1; i <= com; i++) {
        if(visit[i] == 1) cnt = cnt + 1;
    }
    printf("%d", cnt-1);
}
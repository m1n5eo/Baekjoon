#include <bits/stdc++.h>
using namespace std;

int n, m, arr[101][101];
char a;

void dfs(int i, int j, int cnt, int k) {
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    if(arr[i][j] != k) return;

    arr[i][j] = cnt;

    dfs(i-1, j, cnt, k);
    dfs(i+1, j, cnt, k);
    dfs(i, j-1, cnt, k);
    dfs(i, j+1, cnt, k);
}

int main() {
    scanf("%d %d", &m, &n); /// m.세로 n.가로
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &a);
            if(a == 'W') arr[i][j] = 0;
            else if(a == 'B') arr[i][j] = 1;
        }
    }
    int cnt1 = 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                dfs(i, j, cnt1, 0);
                cnt1++;
            }
        }
    }
    int cnt2 = cnt1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 1) {
                dfs(i, j, cnt2, 1);
                cnt2++;
            }
        }
    }

    int WhHap = 0, BlHap = 0, WhCnt, BlCnt;
    for(int k = 2; k < cnt1; k++) {
        WhCnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == k) WhCnt++;
            }
        }
        WhHap += WhCnt*WhCnt;
    }
    for(int k = cnt1; k <= cnt2; k++) {
        BlCnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == k) BlCnt++;
            }
        }
        BlHap += BlCnt*BlCnt;
    }

    printf("%d %d", WhHap, BlHap);
}

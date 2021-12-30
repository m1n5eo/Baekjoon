#include <bits/stdc++.h>
using namespace std;

int n, maxx = -1234567890, dap = -1234567890;
int arr[101][101], chk[101][101]; /// arr0.잠김   arr1.안잠김

void dfs(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= n) return;
    if(chk[x][y] == 0) return;

    chk[x][y] = 0;

    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);
}

void gsr(int t) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] <= t) chk[i][j] = 0;
            else chk[i][j] = 1;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            maxx = max(maxx, arr[i][j]);
        }
    }

    for(int t = 0; t <= maxx; t++) {
        gsr(t);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(chk[i][j] == 1) {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        dap = max(dap, cnt);
    }
    printf("%d", dap);
}
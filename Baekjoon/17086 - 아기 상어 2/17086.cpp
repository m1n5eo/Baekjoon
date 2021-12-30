#include <bits/stdc++.h>
using namespace std;

int n, m, arr[51][51];

void dfs(int i, int j, int dist, int k) {
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    else if(arr[i][j] == -1 && dist != 0) return;
    else if(arr[i][j] != 0 && arr[i][j] != -1 && dist >= arr[i][j]) return;

    if(arr[i][j] != -1) arr[i][j] = dist;

    dfs(i-1, j, dist+1, 1);
    dfs(i+1, j, dist+1, 1);
    dfs(i, j-1, dist+1, 1);
    dfs(i, j+1, dist+1, 1);
    dfs(i-1, j-1, dist+1, 1);
    dfs(i-1, j+1, dist+1, 1);
    dfs(i+1, j-1, dist+1, 1);
    dfs(i+1, j+1, dist+1, 1);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1) arr[i][j] = -1; /// -1이 아기상어
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == -1) {
                dfs(i, j, 0, 0);
            }
        }
    }

    int maxx = -1234567890;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            maxx = max(maxx, arr[i][j]);
        }
    }
    printf("%d", maxx);
}

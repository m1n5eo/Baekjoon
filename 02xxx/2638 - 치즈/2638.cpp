#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m, days = 1;
int arr[101][101], v[101][101];
int dx[4] = {-1, 1, 0, 0},
    dy[4] = {0, 0, -1, 1};
queue<pair<int,int>> q;

void dfs(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    if(arr[x][y] != 0) {
        if(arr[x][y] == 1) {
            v[x][y]++;
            return;
        }
        if(arr[x][y] == days) return;
    }

    arr[x][y] = days;

    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);
}

bool stop() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 1) return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1) q.push({i, j});
        }
    }

    while(1) {
        if(stop() == 0) break;
        days++;
        dfs(0, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == 1 && v[i][j] >= 2) {
                    arr[i][j] = 2;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                //printf("%d ", v[i][j]);
                v[i][j] = 0;
            }
            //printf("\n");
        }
    }
    printf("%d", days-1);
}

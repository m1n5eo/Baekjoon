#include <bits/stdc++.h>
using namespace std;

int n, m, dap = -1;
int arr[1001][1001], visit[1001][1001][2], print[1001][1001];
int dx[4] = {-1, 1, 0, 0},
    dy[4] = {0, 0, -1, 1};

struct pii {
    int a, b, dist;
    bool wall;
};
queue <pii> q;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    int x = 0, y = 0, cnt, bk;
    q.push({x, y, 1, 0});
    visit[x][y][0] = 1;

    while(!q.empty()) {
        x = q.front().a, y = q.front().b, cnt = q.front().dist, bk = q.front().wall;
        q.pop();
        if(x == n-1 && y == m-1) {
            printf("%d", cnt);
            return 0;
        }
        for(int k = 0; k < 4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(arr[nx][ny] == 1 && bk == 0) {
                    q.push({nx, ny, cnt+1, 1});
                    visit[nx][ny][1] = 1;
                }
                else if(arr[nx][ny] == 0 && visit[nx][ny][bk] == 0) {
                    q.push({nx, ny, cnt+1, bk});
                    visit[nx][ny][bk] = 1;
                }
            }
        }
    }
    printf("%d", -1);
}

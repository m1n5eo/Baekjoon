#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m, x = 0, y = 0;
int arr[101][101], visit[101][101], dist[101][101];
int dx[4] = {-1, 1, 0, 0},
    dy[4] = {0, 0, -1, 1};
queue <pair <int,int>> q;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    q.push({x, y});
    dist[x][y] = 1;
    visit[x][y] = 1;

    while(!q.empty()) {
        x = q.front().fi, y = q.front().se;
        q.pop();
        for(int k = 0; k < 4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(arr[nx][ny] == 1 && visit[nx][ny] == 0) {
                    dist[nx][ny] = dist[x][y]+1;
                    visit[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    printf("%d", dist[n-1][m-1]);
}

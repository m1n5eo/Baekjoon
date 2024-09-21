#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m, t;
int StartX, StartY, EndX, EndY;
int arr[1001][1001], timee[1001][1001], chk[1001][1001];
int dx[5] = {0, -1, 1, 0, 0},
    dy[5] = {0, 0, 0, -1, 1}; // 0.상관X  1.위  2.아래  3.왼쪽  4.오른쪽

queue<pair<int,int>> q;

int main() {
    char ch;
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf(" %c", &ch);
            if(ch == '.') arr[i][j] = 0; // 빈칸
            else arr[i][j] = -1; // 벽
        }
    }
    scanf("%d %d %d %d", &StartX, &StartY, &EndX, &EndY);

    int x = StartX, y = StartY;
    q.push({x, y});
    timee[x][y] = 0;
    chk[x][y] = 0;

    while(!q.empty()) {
        x = q.front().fi, y = q.front().se;
        q.pop();
        for(int k = 1; k <= 4; k++) {
            for(int i = 1; i <= t; i++) {
                int nx = x+dx[k]*i, ny = y+dy[k]*i;
                if(nx > 0 && nx <= n && ny > 0 && ny <= m) {
                    if(arr[nx][ny] == 0 && timee[nx][ny] == 0) {
                        q.push({nx, ny});
                        timee[nx][ny] = timee[x][y]+1;
                    }
                    else if(arr[nx][ny] == 0 && timee[nx][ny] == timee[x][y]+1) continue;
                    else break;
                }
            }
        }
        if(x == EndX && y == EndY) break;
    }

    /*for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            printf("%d ", timee[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/

    if(timee[EndX][EndY] == 0) printf("-1");
    else printf("%d", timee[EndX][EndY]);
}

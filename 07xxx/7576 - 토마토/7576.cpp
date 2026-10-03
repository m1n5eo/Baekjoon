#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m;
int arr[1001][1001], days[1001][1001];
int dx[4] = {-1, 1, 0, 0},
    dy[4] = {0, 0, -1, 1};
queue<pair<int,int>> q;

int main() {
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1) {
                q.push({i, j});
                days[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();
        for(int k = 0; k < 4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(arr[nx][ny] == 0) {
                    arr[nx][ny] = 1;
                    days[nx][ny] = days[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }
    }
    int maxx = -1234567890;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            maxx = maxx>days[i][j]? maxx:days[i][j];
            if(arr[i][j] == 0) {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", maxx-1);
}

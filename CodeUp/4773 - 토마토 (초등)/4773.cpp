#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m, h;
int arr[101][101][101], days[101][101][101];
int dx[6] = {-1, 1, 0, 0, 0, 0},
    dy[6] = {0, 0, -1, 1, 0, 0},
    dz[6] = {0, 0, 0, 0, -1, 1};
queue<pair<pair<int,int>,int>> q;

int main() {
    scanf("%d %d %d", &m, &n, &h);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                scanf("%d", &arr[j][k][i]);
                if(arr[j][k][i] == 1) {
                    q.push({{j, k}, i});
                    days[j][k][i] = 1;
                }
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().fi.fi;
        int y = q.front().fi.se;
        int z = q.front().se;
        q.pop();
        for(int k = 0; k < 6; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            int nz = z+dz[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < h) {
                if(arr[nx][ny][nz] == 0) {
                    arr[nx][ny][nz] = 1;
                    days[nx][ny][nz] = days[x][y][z]+1;
                    q.push({{nx, ny}, nz});
                }
            }
        }
    }

    int maxx = -1234567890;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                maxx = maxx>days[j][k][i]? maxx:days[j][k][i];
                if(arr[j][k][i] == 0) {
                    printf("-1");
                    return 0;
                }
            }
        }
    }
    printf("%d", maxx-1);
}
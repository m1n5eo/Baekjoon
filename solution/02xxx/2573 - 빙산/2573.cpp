#include <iostream>
using namespace std;

int n, m;
int pan[333][333], pan_temp[333][333];
bool visited[333][333];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    if(x < 1 || x > n-2 || y < 1 || y > m-2) return;
    else if(visited[x][y] == true) return;
    else if(pan[x][y] == 0) return;

    int cnt = 0;
    visited[x][y] = true;

    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k], ny = y+dy[k];

        if(pan[nx][ny] == 0) cnt += 1;

        dfs(nx, ny);
    }

    if(pan[x][y]-cnt > 0) pan_temp[x][y] = pan[x][y]-cnt;
    else pan_temp[x][y] = 0;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> pan[i][j];
        }
    }

    for(int res = 0; ; res++) {
        int sw = 0;

        for(int i = 1; i < n-1; i++) {
            for(int j = 1; j < m-1; j++) {
                if(pan[i][j] && visited[i][j] == false && sw == 0) {
                    dfs(i, j);
                    sw = 1;
                }
                else if(pan[i][j] && visited[i][j] == false && sw == 1) {
                    cout << res;
                    return 0;
                }

                if(i == n-2 && j == m-2 && sw == 0) {
                    cout << "0";
                    return 0;
                }
            }
        }

        for(int i = 1; i < n-1; i++) {
            for(int j = 1; j < m-1; j++) {
                pan[i][j] = pan_temp[i][j];
                pan_temp[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }

    return 0;
}
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, limit;
int map[222][222];
bool visited[222][222][33];
queue<pair<pair<int, int>, pair<int, int>>> q;

int dx[2][8] = {{-2, -2, -1, 1, 2, 2, 1, -1}, {-1, 0, 1, 0}};
int dy[2][8] = {{-1, 1, 2, 2, 1, -1, -2, -2}, {0, 1, 0, -1}};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> limit;
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    if(n == 1 && m == 1 && map[0][0] == 0) {
        cout << 0;
        return 0;
    }

    q.push({{0, 0}, {0, 0}});
    visited[0][0][0] = true;

    while(q.size()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int jump = q.front().second.first;
        int cnt = q.front().second.second;

        q.pop();

        if(x == n-1 && y == m-1) {
            cout << cnt;
            return 0;
        }

        for(int k = 0; k < 4; k++) {
            int nx = x+dx[1][k];
            int ny = y+dy[1][k];

            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(visited[nx][ny][jump] == false && map[nx][ny] == 0) {
                    q.push({{nx, ny}, {jump, cnt+1}});
                    visited[nx][ny][jump] = true;
                }
            }
        }

        if(jump < limit) {
            for(int k = 0; k < 8; k++) {
                int nx = x+dx[0][k];
                int ny = y+dy[0][k];

                if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if(visited[nx][ny][jump+1] == false && map[nx][ny] == 0) {
                        q.push({{nx, ny}, {jump+1, cnt+1}});
                        visited[nx][ny][jump+1] = true;
                    }
                }
            }
        }
    }

    cout << -1;

    return 0;
}
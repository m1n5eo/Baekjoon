#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, k;
int map[1111][1111];
bool visited[1111][1111][11];
queue<pair<pair<int, int>, pair<int, int>>> q;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for(int j = 0; j < m; j++) {
            if(str[j] == '0') {
                map[i][j] = 0;
            }
            else if(str[j] == '1') {
                map[i][j] = 1;
            }
        }
    }

    visited[0][0][0] = true;
    q.push({{0, 0}, {0, 0}});

    while(q.size()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int dist = q.front().second.second;

        q.pop();

        if(x == n-1 && y == m-1) {
            cout << dist+1;
            return 0;
        }

        for(int t = 0; t < 4; t++) {
            int nx = x+dx[t];
            int ny = y+dy[t];

            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(map[nx][ny] == 0 && visited[nx][ny][cnt] == false) {
                    visited[nx][ny][cnt] = true;
                    q.push({{nx, ny}, {cnt, dist+1}});
                }
                else if(map[nx][ny] == 1 && visited[nx][ny][cnt+1] == false && cnt < k) {
                    visited[nx][ny][cnt+1] = true;
                    q.push({{nx, ny}, {cnt+1, dist+1}});
                }
            }
        }
    }

    cout << -1;

    return 0;
}
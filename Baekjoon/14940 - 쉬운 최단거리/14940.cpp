#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define fi first
#define se second

int n, m;
int map[1111][1111];
bool visited[1111][1111];
queue<pair<int, int>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                q.push({i, j});
                map[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }

    while(q.size()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();

        for(int k = 0; k < 4; k++) {
            int nx = x+dx[k], ny = y+dy[k];
            if(map[nx][ny] == 1 && visited[nx][ny] == false) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                map[nx][ny] = map[x][y]+1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] && visited[i][j] == false) cout << "-1 ";
            else cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
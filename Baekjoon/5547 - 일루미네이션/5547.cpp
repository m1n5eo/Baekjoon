#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, cnt;
int map[111][111];
bool visited[111][111];
queue<pair<int, int>> q;

int dx[2][6] = {{-1, -1, 0, 1, 1, 0}, {-1, -1, 0, 1, 1, 0}};
int dy[2][6] = {{0, 1, 1, 1, 0, -1}, {-1, 0, 1, 0, -1, -1}};

void bfs(int ii, int jj, int what) {

}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0 && visited[i][j] == false && (i == 0 || i == n-1 || j == 0 || j == m-1)) {
                q.push({i, j});
                map[i][j] = 2;
                visited[i][j] = true;

                while(q.size()) {
                    int x = q.front().first;
                    int y = q.front().second;

                    q.pop();

                    for(int k = 0; k < 6; k++) {
                        int nx = x+dx[x%2][k];
                        int ny = y+dy[x%2][k];

                        if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                            if(map[nx][ny] == 0 && visited[nx][ny] == false) {
                                q.push({nx, ny});
                                map[nx][ny] = 2;
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 1) {
                for(int k = 0; k < 6; k++) {
                    int nx = i+dx[i%2][k];
                    int ny = j+dy[i%2][k];

                    if((0 <= nx && nx < n && 0 <= ny && ny < m) && map[nx][ny] == 2) cnt += 1;
                    else if(!(0 <= nx && nx < n && 0 <= ny && ny < m)) cnt += 1;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n, res = 1234567890;
int map[111][111][2];

queue<pair<int,int>> q;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void init(int x, int y, int cnt) {
    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        if(0 <= nx && nx < n && 0 <= ny && ny < n) {
            if(map[nx][ny][0] == 1) {
                map[nx][ny][0] = -1;
                map[nx][ny][1] = cnt;

                init(nx, ny, cnt);
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j][0];
        }
    }

    int temp = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j][0] == 1) {
                map[i][j][0] = -1;
                map[i][j][1] = temp;

                init(i, j, temp);

                temp += 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j][0] == -1) {
                for(int k = 0; k < 4; k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];

                    if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                        if(map[nx][ny][0] == 0) {
                            q.push({i, j});
                            break;
                        }
                    }
                }
            }
        }
    }

    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int k = 0; k < 4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];

            if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                if(map[nx][ny][0] > 0 && map[nx][ny][1] != map[x][y][1]) {
                    if(map[x][y][0] == -1) res = min(res, map[nx][ny][0]);
                    else res = min(res, map[x][y][0]+map[nx][ny][0]);
                }
                else if(map[nx][ny][0] == 0) {
                    if(map[x][y][0] == -1) map[nx][ny][0] = 1;
                    else map[nx][ny][0] = map[x][y][0]+1;

                    map[nx][ny][1] = map[x][y][1];
                    
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << res;

    return 0;
}
#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int n, m;
int map[55][55];
bool visited[55][55];

queue<pair<pair<int, int>, int>> human;
queue<pair<int, int>> water;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for(int j = 0; j < m; j++) {
            if(str[j] == '.') {
                map[i][j] = 0;
            }
            else if(str[j] == '*') {
                map[i][j] = -2;

                water.push({i, j});
            }
            else if(str[j] == 'X') {
                map[i][j] = -3;
            }
            else if(str[j] == 'D') {
                map[i][j] = -1;
            }
            else if(str[j] == 'S') {
                map[i][j] = 0;
                visited[i][j] = true;

                human.push({{i, j}, 0});
            }
        }
    }

    while(human.size()) {
        int water_len = water.size();

        for(int len = 0; len < water_len; len++) {
            int x = water.front().first;
            int y = water.front().second;

            water.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];

                if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if(map[nx][ny] == 0) {
                        map[nx][ny] = -2;

                        water.push({nx, ny});
                    }
                }
            }
        }

        int human_len = human.size();

        for(int len = 0; len < human_len; len++) {
            int x = human.front().first.first;
            int y = human.front().first.second;
            int cnt = human.front().second;

            human.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];

                if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if(visited[nx][ny] == false && map[nx][ny] == 0) {
                        visited[nx][ny] = true;

                        human.push({{nx, ny}, cnt+1});
                    }
                    else if(map[nx][ny] == -1) {
                        cout << cnt+1;

                        return 0;
                    }
                }
            }
        }
    }

    cout << "KAKTUS";

    return 0;
}
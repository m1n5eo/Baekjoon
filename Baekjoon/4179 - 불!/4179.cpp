#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int n, m;
int map[1111][1111];
bool visited[1111][1111];
queue<pair<pair<int, int>, int>> human;
queue<pair<int, int>> fire;

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
            if(str[j] == '#') {
                map[i][j] = -1;
            }
            else if(str[j] == 'J') {
                map[i][j] = 0;
                visited[i][j] = true;

                human.push({{i, j}, 0});
            }
            else if(str[j] == '.') {
                map[i][j] = 0;
            }
            else if(str[j] == 'F') {
                map[i][j] = -2;

                fire.push({i, j});
            }
        }
    }

    while(human.size()) {
        int fire_len = fire.size();

        for(int i = 0; i < fire_len; i++) {
            int fire_x = fire.front().first;
            int fire_y = fire.front().second;

            fire.pop();

            for(int k = 0; k < 4; k++) {
                int nx = fire_x+dx[k];
                int ny = fire_y+dy[k];

                if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if(map[nx][ny] >= 0) {
                        fire.push({nx, ny});
                        map[nx][ny] = -2;
                    }
                }
            }
        }
        
        int human_len = human.size();

        for(int i = 0; i < human_len; i++) {
            int human_x = human.front().first.first;
            int human_y = human.front().first.second;
            int cnt = human.front().second;

            human.pop();

            if(human_x == 0 || human_x == n-1 || human_y == 0 || human_y == m-1) {
                cout << cnt+1;
                return 0;
            }

            for(int k = 0; k < 4; k++) {
                int nx = human_x+dx[k];
                int ny = human_y+dy[k];

                if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if(visited[nx][ny] == false && map[nx][ny] >= 0) {
                        human.push({{nx, ny}, cnt+1});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
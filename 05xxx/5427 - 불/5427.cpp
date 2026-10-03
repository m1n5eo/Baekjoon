#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

#define fi first
#define se second

int t, n, m;
int building[1111][1111], dist[1111][1111];
string str[1111];
queue<pair<int, int>> human, fire;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        cin >> m >> n;
        for(int i = 0; i < n; i++) {
            cin >> str[i];
            for(int j = 0; j < m; j++) {
                dist[i][j] = 0;

                if(str[i][j] == '.') building[i][j] = 0;
                else if(str[i][j] == '#') building[i][j] = 9;
                else if(str[i][j] == '*') {
                    building[i][j] = 1;
                    fire.push({i, j});
                }
                else if(str[i][j] == '@') {
                    dist[i][j] = 1;
                    human.push({i, j});
                }
            }
        }

        int flag = 0;

        while(human.size()) {
            int fire_len = fire.size();

            for(int i = 0; i < fire_len; i++) {
                int fire_x = fire.front().fi, fire_y = fire.front().se;
                fire.pop();

                for(int k = 0; k < 4; k++) {
                    if(0 <= fire_x+dx[k] && fire_x+dx[k] < n && 0 <= fire_y+dy[k] && fire_y+dy[k] < m) {
                        if(building[fire_x+dx[k]][fire_y+dy[k]] == 0) {
                            fire.push({fire_x+dx[k], fire_y+dy[k]});
                            building[fire_x+dx[k]][fire_y+dy[k]] = 1;
                        }
                    }
                }
            }

            int human_len = human.size();

            for(int i = 0; i < human_len; i++) {
                int human_x = human.front().fi, human_y = human.front().se;
                human.pop();

                if(human_x == 0 || human_x == n-1 || human_y == 0 || human_y == m-1) {
                    cout << dist[human_x][human_y] << "\n";
                    flag = 1;
                    break;
                }

                for(int k = 0; k < 4; k++) {
                    if(0 <= human_x+dx[k] && human_x+dx[k] < n && 0 <= human_y+dy[k] && human_y+dy[k] < m) {
                        if(building[human_x+dx[k]][human_y+dy[k]] == 0 && dist[human_x+dx[k]][human_y+dy[k]] == 0) {
                            human.push({human_x+dx[k], human_y+dy[k]});
                            dist[human_x+dx[k]][human_y+dy[k]] = dist[human_x][human_y]+1;
                        }
                    }
                }
            }

            if(flag == 1) break;
        }

        if(flag == 0) cout << "IMPOSSIBLE\n";

        while(fire.size()) fire.pop();
        while(human.size()) human.pop();
    }

    return 0;
}
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

struct coordinate {
    int x, y;
};

int main() {
    int n, m, t;
    string str;
    coordinate start, end;
    vector<vector<int>> v(MAX, vector<int>(MAX, 0)), time(MAX, vector<int>(MAX, 0));
    queue<coordinate> bfs;

    int dx[5] = {0, -1, 1, 0, 0},
        dy[5] = {0, 0, 0, -1, 1};

    cin >> n >> m >> t;

    for(int i = 1; i <= n; i++) {
        cin >> str;

        for(int j = 0; j < m; j++) {
            if(str[j] == '.') v[i][j+1] = 0;
            else v[i][j+1] = -1;
        }
    }

    cin >> start.x >> start.y >> end.x >> end.y;

    bfs.push(start);
    time[start.x][start.y] = 0;

    while(bfs.size()) {
        coordinate now = bfs.front();
        bfs.pop();

        for(int k = 1; k <= 4; k++) {
            for(int i = 1; i <= t; i++) {
                coordinate next = {now.x+dx[k]*i, now.y+dy[k]*i};

                if(0 < next.x && next.x <= n && 0 < next.y && next.y <= m) {
                    if(v[next.x][next.y] == 0 && time[next.x][next.y] == 0) {
                        bfs.push(next);
                        time[next.x][next.y] = time[now.x][now.y]+1;
                    }
                    else if(v[next.x][next.y] == 0 && time[next.x][next.y] == time[now.x][now.y]+1) {
                        continue;
                    }
                    else break;
                }
            }
        }

        if(now.x == end.x && now.y == end.y) {
            break;
        }
    }

    if(time[end.x][end.y] == 0) cout << -1;
    else cout << time[end.x][end.y];
}
#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

struct type {
    int x, y, c, w, d;
};

int n, m, limit;
int map[1111][1111];
bool visited[1111][1111][11][2];
queue<type> q;

int dx[5] = {-1, 0, 1, 0, 0};
int dy[5] = {0, 1, 0, -1, 0};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> limit;
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

    q.push({0, 0, 0, 0, 1});
    visited[0][0][0][0] = true;

    while(q.size()) {
        int now_x = q.front().x;
        int now_y = q.front().y;
        int cnt = q.front().c;
        int wall = q.front().w;
        int day = q.front().d;

        q.pop();

        if(now_x == n-1 && now_y == m-1) {
            cout << cnt+1;
            return 0;
        }

        for(int k = 0; k < 5; k++) {
            int nx = now_x+dx[k];
            int ny = now_y+dy[k];

            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(map[nx][ny] == 0 && visited[nx][ny][wall][day] == false) {
                    visited[nx][ny][wall][day] = true;
                    q.push({nx, ny, cnt+1, wall, 1-day});
                }
                if(map[nx][ny] == 1 && day == 1 && wall < limit && visited[nx][ny][wall+1][day] == false) {
                    visited[nx][ny][wall+1][day] = true;
                    q.push({nx, ny, cnt+1, wall+1, 1-day});
                }
                if(k == 4 && map[nx][ny] == 1 && day == 0 && visited[nx][ny][wall][day] == false) {
                    visited[nx][ny][wall][day] = true;
                    q.push({nx, ny, cnt+1, wall, 1-day});
                }
            }
        }
    }

    cout << -1;
    
    return 0;
}
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int t, n, now_x, now_y, go_x, go_y;
int cnt[333][333];
bool visited[333][333];
queue<pair<int, int>> q;
int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cnt[i][j] = 0;
            visited[i][j] = false;
        }
    }

    while(q.size()) q.pop();

    return;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n;
        cin >> now_x >> now_y;
        cin >> go_x >> go_y;

        q.push({now_x, now_y});
        cnt[now_x][now_y] = 0;
        visited[now_x][now_y] = true;

        while(q.size()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            if(x == go_x && y == go_y) {
                cout << cnt[go_x][go_y] << "\n";
                break;
            }

            for(int k = 0; k < 8; k++) {
                int nx = x+dx[k], ny = y+dy[k];

                if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if(visited[nx][ny] == false) {
                        cnt[nx][ny] = cnt[x][y]+1;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        init();
    }

    return 0;
}
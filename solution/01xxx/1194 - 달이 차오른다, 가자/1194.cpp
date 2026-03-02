#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    int x, y, check;
};

int solution() {
    int n, m;
    cin >> n >> m;
    vector<string> miro(n);
    queue<type> bfs;
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(1<<6, false)));
    for(int i = 0; i < n; i++) {
        cin >> miro[i];
        for(int j = 0; j < m; j++) {
            if(miro[i][j] == '0') {
                miro[i][j] = '.';
                bfs.push({i, j, 0});
                visited[i][j][0] = true;
            }
        }
    }

    int ret = 0;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    while(!bfs.empty()) {
        int bs = bfs.size(); ret += 1;
        for(int _ = 0; _ < bs; _++) {
            type now = bfs.front(); bfs.pop();
            for(int k = 0; k < 4; k++) {
                type next = {now.x+dx[k], now.y+dy[k], now.check};
                if(!(0 <= next.x && next.x < n && 0 <= next.y && next.y < m)) continue;
                else if(miro[next.x][next.y] == '#') continue;
                else if(miro[next.x][next.y] == '1') return ret;
                else if(miro[next.x][next.y] == '.') {
                    if(visited[next.x][next.y][next.check]) continue;
                    bfs.push({next.x, next.y, next.check});
                    visited[next.x][next.y][next.check] = true;
                }
                else if('a' <= miro[next.x][next.y] && miro[next.x][next.y] <= 'f') {
                    next.check |= (1<<(miro[next.x][next.y]-'a'));
                    if(visited[next.x][next.y][next.check]) continue;
                    bfs.push({next.x, next.y, next.check});
                    visited[next.x][next.y][next.check] = true;
                }
                else if('A' <= miro[next.x][next.y] && miro[next.x][next.y] <= 'F') {
                    if(visited[next.x][next.y][next.check]) continue;
                    else if((next.check & (1<<(miro[next.x][next.y]-'A'))) != 0) {
                        bfs.push({next.x, next.y, next.check});
                        visited[next.x][next.y][next.check] = true;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    FASTIO
    cout << solution();
}
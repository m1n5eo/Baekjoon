#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    int x, y, cnt;
    bool check;
};

int solve() {
    int n, m;
    pair<int, int> start, end;
    cin >> n >> m;
    cin >> start.first >> start.second;
    cin >> end.first >> end.second;
    vector<vector<int>> maze(n+1, vector<int>(m+1, 0));
    vector<vector<vector<bool>>> visit(n+1, vector<vector<bool>>(m+1, vector<bool>(2, false)));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int temp; cin >> temp;
            if(temp == 0) maze[i][j] = 0;
            else if(temp == 1) maze[i][j] = -1;
        }
    }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    queue<type> bfs;
    bfs.push({start.first, start.second, 0, false});
    visit[start.first][start.second][0] = true;
    while(!bfs.empty()) {
        type now = bfs.front();
        bfs.pop();
        for(int k = 0; k < 4; k++) {
            type next = {now.x+dx[k], now.y+dy[k], now.cnt+1, now.check};
            if(1 <= next.x && next.x <= n && 1 <= next.y && next.y <= m) {
                if(maze[next.x][next.y] == 0 && visit[next.x][next.y][next.check] == false) {
                    if(next.x == end.first && next.y == end.second) return next.cnt;
                    visit[next.x][next.y][next.check] = true;
                    bfs.push(next);
                }
                else if(maze[next.x][next.y] == -1 && now.check == false && visit[next.x][next.y][true] == false) {
                    if(next.x == end.first && next.y == end.second) return next.cnt;
                    visit[next.x][next.y][true] = true;
                    bfs.push({next.x, next.y, next.cnt, true});
                }
            }
        }
    }
    return -1;
}

int main() {
    FASTIO
    cout << solve();
}
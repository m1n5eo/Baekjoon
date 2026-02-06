#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55

struct type {
    int x, y, dir, eat;
};

int solve() {
    int n, m, cnt = 1;
    cin >> n >> m;
    vector<vector<int>> gamepan(n, vector<int>(m, 0));
    vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(5, vector<bool>(4, false))));
    queue<type> bfs;
    for(int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for(int j = 0; j < m; j++) {
            if(temp[j] == '#') gamepan[i][j] = 9;
            else if(temp[j] == 'C') gamepan[i][j] = cnt++;
            else if(temp[j] == 'S') {
                visited[i][j][4][0] = true;
                bfs.push({i, j, 4, 0});
            }
        }
    }
    
    int result = 0;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    while(!bfs.empty()) {
        int bs = bfs.size();
        result += 1;
        for(int _ = 0; _ < bs; _++) {
            type now = bfs.front(); bfs.pop();
            for(int k = 0; k < 4; k++) {
                type next = {now.x+dx[k], now.y+dy[k], k, now.eat};
                if(k == now.dir) continue;
                else if(!(0 <= next.x && next.x < n && 0 <= next.y && next.y < m)) continue;
                else if(visited[next.x][next.y][next.dir][next.eat]) continue;
                else if(gamepan[next.x][next.y] == 9) continue;

                if(gamepan[next.x][next.y] == 1) next.eat |= 1;
                else if(gamepan[next.x][next.y] == 2) next.eat |= 2;

                if(next.eat == 3) return result;
                visited[next.x][next.y][next.dir][next.eat] = true;
                bfs.push(next);
            }
        }
    }
    return -1;
}

int main() {
    FASTIO
    cout << solve();
}
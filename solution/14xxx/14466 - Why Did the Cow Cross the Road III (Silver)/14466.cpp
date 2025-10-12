#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

int solve() {
    int n, m, r;
    cin >> n >> m >> r;
    pair<int, int> a, b;
    vector<vector<int>> board(n+1, vector<int>(n+1, 0));
    vector<vector<vector<bool>>> able(n+1, vector<vector<bool>>(n+1, vector<bool>(4, true)));
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int i = 0; i < r; i++) {
        cin >> a.first >> a.second >> b.first >> b.second;
        for(int k = 0; k < 4; k++) {
            if(a.first+dx[k] == b.first && a.second+dy[k] == b.second) {
                able[a.first][a.second][k] = false;
                able[b.first][b.second][(k+2)%4] = false;
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(board[i][j] == 0) {
                queue<pair<int, int>> bfs;
                board[i][j] = ++cnt;
                bfs.push({i, j});
                while(!bfs.empty()) {
                    pair<int, int> now = bfs.front();
                    bfs.pop();
                    for(int k = 0; k < 4; k++) {
                        pair<int, int> next = {now.first+dx[k], now.second+dy[k]};
                        if(1 <= next.first && next.first <= n && 1 <= next.second && next.second <= n) {
                            if(able[now.first][now.second][k] == true && board[next.first][next.second] == 0) {
                                board[next.first][next.second] = cnt;
                                bfs.push(next);
                            }
                        }
                    }
                }
            }
        }
    }

    map<int, int> preprecessing;
    for(int i = 0; i < m; i++) {
        cin >> a.first >> a.second;
        if(preprecessing.find(board[a.first][a.second]) != preprecessing.end()) preprecessing[board[a.first][a.second]] += 1;
        else preprecessing[board[a.first][a.second]] = 1;
    }

    int ret = 0;
    for(pair<int, int> p : preprecessing) {
        ret += (m-p.second)*p.second;
        m -= p.second;
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
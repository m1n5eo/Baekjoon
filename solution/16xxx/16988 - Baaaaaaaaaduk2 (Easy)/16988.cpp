#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> init(n+2, vector<int>(m+2, 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> init[i][j];
        }
    }

    int ret = 0;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int x1 = 1; x1 <= n; x1++) {
        for(int y1 = 1; y1 <= m; y1++) {
            for(int x2 = x1; x2 <= n; x2++) {
                for(int y2 = 1; y2 <= m; y2++) {
                    vector<vector<int>> board = init;
                    if(x1*(m+2)+y1 >= x2*(m+2)+y2) continue;
                    else if(board[x1][y1] != 0 || board[x2][y2] != 0) continue;
                    board[x1][y1] = 1; board[x2][y2] = 1;
                    int sum = 0;
                    for(int i = 1; i <= n; i++) {
                        for(int j = 1; j <= m; j++) {
                            if(board[i][j] != 1) {
                                int cnt0 = (board[i][j] == 0? 1 : 0), cnt2 = (board[i][j] == 2? 1 : 0);
                                queue<pair<int, int>> bfs;
                                bfs.push({i, j});
                                board[i][j] = 1;
                                while(!bfs.empty()) {
                                    pair<int, int> now = bfs.front();
                                    bfs.pop();
                                    for(int k = 0; k < 4; k++) {
                                        pair<int, int> next = {now.first+dx[k], now.second+dy[k]};
                                        if(!(0 <= next.first && next.first < n+2 && 0 <= next.second && next.second < m+2)) continue;
                                        else if(board[next.first][next.second] == 1) continue;
                                        else if(board[next.first][next.second] != 1) {
                                            if(board[next.first][next.second] == 0) cnt0 += 1;
                                            else if(board[next.first][next.second] == 2) cnt2 += 1;
                                            bfs.push(next);
                                            board[next.first][next.second] = 1;
                                        }
                                    }
                                }
                                if(cnt0 == 0) {
                                    sum += cnt2;
                                }
                            }
                        }
                    }
                    ret = max(ret, sum);
                }
            }
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
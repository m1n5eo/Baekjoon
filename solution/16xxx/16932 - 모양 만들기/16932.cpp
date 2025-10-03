#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int n, m, temp;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> temp;
            if(temp == 0) board[i][j] = 0;
            else board[i][j] = -1;
        }
    }

    int idx = 0, ret = 0;
    vector<int> cnt(1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == -1) {
                int count = 1;
                queue<pair<int, int>> bfs;
                bfs.push({i, j});
                board[i][j] = ++idx;
                while(!bfs.empty()) {
                    pair<int, int> now = bfs.front();
                    bfs.pop();
                    for(int k = 0; k < 4; k++) {
                        pair<int, int> next = {now.first+dx[k], now.second+dy[k]};
                        if(0 <= next.first && next.first < n && 0 <= next.second && next.second < m) {
                            if(board[next.first][next.second] == -1) {
                                bfs.push(next);
                                board[next.first][next.second] = idx;
                                count += 1;
                            }
                        }
                    }
                }
                cnt.push_back(count);
                ret = max(ret, count-1);
            }
        }
    }

    // cout << "\n" << "board" << "\n";
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    // cout << "\n" << "cnt" << " : ";
    // for(int i = 1; i <= idx; i++) cout << cnt[i] << " ";
    // cout << "\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0) {
                set<int> s;
                for(int k = 0; k < 4; k++) {
                    pair<int, int> next = {i+dx[k], j+dy[k]};
                    if(0 <= next.first && next.first < n && 0 <= next.second && next.second < m) s.insert(board[next.first][next.second]);
                }
                int sum = 1;
                for(int ss : s) sum += cnt[ss];
                ret = max(ret, sum);
            }
        }
    }

    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
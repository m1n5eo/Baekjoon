#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define INF 1234567890

struct pqcmp {
    bool operator()(pair<pii, int> a, pair<pii, int> b) {
        return a.second > b.second;
    }
};

int solve() {
    int n, m;
    cin >> m >> n;
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<int>> broken(n, vector<int>(m, INF));
    for(int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for(int j = 0; j < m; j++) {
            board[i][j] = temp[j] - '0';
        }
    }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    priority_queue<pair<pii, int>, vector<pair<pii, int>>, pqcmp> pq;
    pq.push({{0, 0}, 0});
    broken[0][0] = 0;
    while(!pq.empty()) {
        pair<pii, int> now = pq.top(); pq.pop();
        for(int k = 0; k < 4; k++) {
            pair<pii, int> next = {{now.first.first+dx[k], now.first.second+dy[k]}, now.second};
            if(!(0 <= next.first.first && next.first.first < n && 0 <= next.first.second && next.first.second < m)) continue;
            else if(board[next.first.first][next.first.second] == 0) {
                if(broken[next.first.first][next.first.second] > next.second) {
                    broken[next.first.first][next.first.second] = next.second;
                    pq.push(next);
                }
            }
            else if(board[next.first.first][next.first.second] == 1) {
                if(broken[next.first.first][next.first.second] > next.second+1) {
                    broken[next.first.first][next.first.second] = next.second+1;
                    pq.push({next.first, next.second+1});
                }
            }
        }
    }
    return broken[n-1][m-1];
}

int main() {
    FASTIO
    cout << solve();
}
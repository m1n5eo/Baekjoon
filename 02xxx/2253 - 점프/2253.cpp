#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11111

int solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> visit(MAX, vector<bool>(MAX, false));
    for(int i = 0; i < m; i++) {
        int temp; cin >> temp;
        for(int j = 0; j <= n; j++) visit[temp][j] = true;
    }

    int ret = 0;
    vector<int> dx = {-1, 0, 1};
    queue<pair<int, int>> bfs;
    bfs.push({1, 0});
    visit[1][0] = true;
    while(!bfs.empty()) {
        int bfs_size = bfs.size();
        ret += 1;
        for(int _ = 0; _ < bfs_size; _++) {
            pair<int, int> now = bfs.front();
            bfs.pop();
            for(int k = 0; k < 3; k++) {
                pair<int, int> next = {now.first+now.second+dx[k], now.second+dx[k]};
                if(next.second > 0 && visit[next.first][next.second] == false) {
                    if(next.first == n) return ret;
                    else if(next.first < n) {
                        bfs.push(next);
                        visit[next.first][next.second] = true;
                    }
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
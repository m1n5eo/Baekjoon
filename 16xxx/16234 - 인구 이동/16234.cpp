#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<vector<int>> people(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> people[i][j];
        }
    }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int ret = 0; ; ret++) {
        bool check = true;
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visit[i][j] == false) {
                    int cnt = people[i][j];
                    queue<pair<int, int>> bfs;
                    set<pair<int, int>> s;
                    visit[i][j] = true;
                    bfs.push({i, j});
                    s.insert({i, j});
                    while(!bfs.empty()) {
                        pair<int, int> now = bfs.front();
                        bfs.pop();
                        for(int k = 0; k < 4; k++) {
                            pair<int, int> next = {now.first+dx[k], now.second+dy[k]};
                            if(0 <= next.first && next.first < n && 0 <= next.second && next.second < n) {
                                if(visit[next.first][next.second] == false) {
                                    if(l <= abs(people[now.first][now.second] - people[next.first][next.second]) && abs(people[now.first][now.second] - people[next.first][next.second]) <= r) {
                                        cnt += people[next.first][next.second];
                                        visit[next.first][next.second] = true;
                                        bfs.push(next);
                                        s.insert(next);
                                    }
                                }
                            }
                        }
                    }
                    int k = cnt/s.size();
                    for(pair<int, int> ss : s) {
                        if(people[ss.first][ss.second] != k) check = false;
                        people[ss.first][ss.second] = k;
                    }
                }
            }
        }
        if(check == true) return ret;
    }
}

int main() {
    FASTIO
    cout << solve();
}
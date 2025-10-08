#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX 111

struct compare {
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        return a.second > b.second;
    }
};

int solve() {
    int n, m, x, y, a, b;
    cin >> n >> m;
    vector<vector<vector<pair<int, int>>>> room(n+1, vector<vector<pair<int, int>>>(n+1, vector<pair<int, int>>(0)));
    for(int _ = 0; _ < m; _++) {
        cin >> x >> y >> a >> b;
        room[x][y].push_back({a, b});
    }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<vector<pair<bool, bool>>> on(n+1, vector<pair<bool, bool>>(n+1, {false, false}));
    queue<pair<int, int>> q;
    on[1][1] = {true, true};
    q.push({1, 1});
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        for(pair<int, int> next : room[now.first][now.second]) {
            if(on[next.first][next.second].first == true) continue;
            on[next.first][next.second].first = true;
            for(int k = 0; k < 4; k++) {
                pair<int, int> nnext = {next.first+dx[k], next.second+dy[k]};
                if(!(1 <= nnext.first && nnext.first <= n && 1 <= nnext.second && nnext.second <= n)) continue;
                else if(on[nnext.first][nnext.second].second == true) {
                    on[nnext.first][nnext.second].second = true;
                    q.push(nnext);
                    break;
                }
            }
        }
        for(int k = 0; k < 4; k++) {
            pair<int, int> next = {now.first+dx[k], now.second+dy[k]};
            if(!(1 <= next.first && next.first <= n && 1 <= next.second && next.second <= n)) continue;
            else if(on[next.first][next.second].first == false || on[next.first][next.second].second == true) continue;
            on[next.first][next.second].second = true;
            q.push(next);
        }
    }

    // cout << "\n" << "on.second" << "\n";
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << on[i][j].second << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    int ret = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(on[i][j].first == true) ret += 1;
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
#include <iostream>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<int> dx = {-3, -3, -2, 2, 3, 3, 2, -2};
vector<int> dy = {-2, 2, 3, 3, 2, -2, -3, -3};
vector<vector<int>> ddx = {{-1, -2, -3}, {-1, -2, -3}, {0, -1, -2}, {0, 1, 2}, {1, 2, 3}, {1, 2, 3}, {0, 1, 2}, {0, -1, -2}};
vector<vector<int>> ddy = {{0, -1, -2}, {0, 1, 2}, {1, 2, 3}, {1, 2, 3}, {0, 1, 2}, {0, -1, -2}, {-1, -2, -3}, {-1, -2, -3}};

int solution() {
    int n = 10, m = 9;
    pair<int, int> king, sang;
    cin >> sang.first >> sang.second;
    cin >> king.first >> king.second;

    int ret = 0;
    queue<pair<int, int>> bfs;
    bfs.push(sang);
    while(!bfs.empty()) {
        int bs = bfs.size(); ret += 1;
        for(int _ = 0; _ < bs; _++) {
            pair<int, int> now = bfs.front();
            bfs.pop();
            for(int k = 0; k < 8; k++) {
                pair<int, int> next = {now.first+dx[k], now.second+dy[k]};
                if(king == next) return ret;
                else if(!(0 <= next.first && next.first < n && 0 <= next.second && next.second < m)) continue;
                else if(king == make_pair(now.first+ddx[k][0], now.second+ddy[k][0])) continue;
                else if(king == make_pair(now.first+ddx[k][1], now.second+ddy[k][1])) continue;
                else if(king == make_pair(now.first+ddx[k][2], now.second+ddy[k][2])) continue;
                bfs.push(next);
            }
        }
    }
    return -1;
}

int main() {
    FASTIO
    cout << solution();
}
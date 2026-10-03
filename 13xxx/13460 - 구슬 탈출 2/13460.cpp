#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

pair<vector<vector<int>>, pair<int, int>> move(vector<vector<int>> board, int k) {
    pair<vector<vector<int>>, pair<int, int>> ret = {board, {false, false}};
    int n = board.size(), m = board[0].size();
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    pair<int, int> red = {-1, -1}, blue = {-1, -1};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(ret.first[i][j] == 2) red = {i, j};
            else if(ret.first[i][j] == 3) blue = {i, j};
        }
    }

    if((k == 0 && red.first < blue.first) || (k == 1 && red.first > blue.first) || (k == 2 && red.second < blue.second) || (k == 3 && red.second > blue.second)) {
        while(ret.first[red.first+dx[k]][red.second+dy[k]] != 9 && ret.first[red.first+dx[k]][red.second+dy[k]] != 3) {
            ret.first[red.first][red.second] = 0;
            if(ret.first[red.first+dx[k]][red.second+dy[k]] == 0) {
                ret.first[red.first+dx[k]][red.second+dy[k]] = 2;
                red = {red.first+dx[k], red.second+dy[k]};
            }
            else if(ret.first[red.first+dx[k]][red.second+dy[k]] == 1) {
                ret.second.first = true;
                break;
            }
        }
        while(ret.first[blue.first+dx[k]][blue.second+dy[k]] != 9 && ret.first[blue.first+dx[k]][blue.second+dy[k]] != 2) {
            ret.first[blue.first][blue.second] = 0;
            if(ret.first[blue.first+dx[k]][blue.second+dy[k]] == 0) {
                ret.first[blue.first+dx[k]][blue.second+dy[k]] = 3;
                blue = {blue.first+dx[k], blue.second+dy[k]};
            }
            else if(ret.first[blue.first+dx[k]][blue.second+dy[k]] == 1) {
                ret.second.second = true;
                break;
            }
        }
    }
    else {
        while(ret.first[blue.first+dx[k]][blue.second+dy[k]] != 9 && ret.first[blue.first+dx[k]][blue.second+dy[k]] != 2) {
            ret.first[blue.first][blue.second] = 0;
            if(ret.first[blue.first+dx[k]][blue.second+dy[k]] == 0) {
                ret.first[blue.first+dx[k]][blue.second+dy[k]] = 3;
                blue = {blue.first+dx[k], blue.second+dy[k]};
            }
            else if(ret.first[blue.first+dx[k]][blue.second+dy[k]] == 1) {
                ret.second.second = true;
                break;
            }
        }
        while(ret.first[red.first+dx[k]][red.second+dy[k]] != 9 && ret.first[red.first+dx[k]][red.second+dy[k]] != 3) {
            ret.first[red.first][red.second] = 0;
            if(ret.first[red.first+dx[k]][red.second+dy[k]] == 0) {
                ret.first[red.first+dx[k]][red.second+dy[k]] = 2;
                red = {red.first+dx[k], red.second+dy[k]};
            }
            else if(ret.first[red.first+dx[k]][red.second+dy[k]] == 1) {
                ret.second.first = true;
                break;
            }
        }
    }
    return ret;
}

int solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for(int j = 0; j < m; j++) {
            if(temp[j] == '#') board[i][j] = 9;
            else if(temp[j] == '.') board[i][j] = 0;
            else if(temp[j] == 'O') board[i][j] = 1;
            else if(temp[j] == 'R') board[i][j] = 2;
            else if(temp[j] == 'B') board[i][j] = 3;
        }
    }

    int ret = 0;
    queue<pair<vector<vector<int>>, int>> bfs;
    bfs.push({board, 0});
    while(!bfs.empty()) {
        pair<vector<vector<int>>, int> now = bfs.front();
        bfs.pop();
        for(int k = 0; k < 4; k++) {
            pair<vector<vector<int>>, pair<int, int>> m = move(now.first, k);
            pair<vector<vector<int>>, int> next = {m.first, now.second+1};
            if(now.first == next.first) continue;
            else if(m.second.second == true) continue;
            else if(m.second.first == true && m.second.second == false) return next.second;
            else if(m.second.first == false && m.second.second == false) {
                if(next.second >= 10) continue;
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
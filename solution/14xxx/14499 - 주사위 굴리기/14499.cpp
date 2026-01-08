#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<vector<int>> rotate(vector<vector<int>> dice, int mode) {
    vector<vector<int>> ret(4, vector<int>(3, 0));
    if(mode == 0) ret = dice;
    else if(mode == 1) {
        ret[0][1] = dice[0][1];
        ret[1][0] = dice[3][1];
        ret[1][1] = dice[1][0];
        ret[1][2] = dice[1][1];
        ret[2][1] = dice[2][1];
        ret[3][1] = dice[1][2];
    }
    else if(mode == 2) {
        ret[0][1] = dice[0][1];
        ret[1][0] = dice[1][1];
        ret[1][1] = dice[1][2];
        ret[1][2] = dice[3][1];
        ret[2][1] = dice[2][1];
        ret[3][1] = dice[1][0];
    }
    else if(mode == 3) {
        ret[0][1] = dice[1][1];
        ret[1][0] = dice[1][0];
        ret[1][1] = dice[2][1];
        ret[1][2] = dice[1][2];
        ret[2][1] = dice[3][1];
        ret[3][1] = dice[0][1];
    }
    else if(mode == 4) {
        ret[0][1] = dice[3][1];
        ret[1][0] = dice[1][0];
        ret[1][1] = dice[0][1];
        ret[1][2] = dice[1][2];
        ret[2][1] = dice[1][1];
        ret[3][1] = dice[2][1];
    }
    return ret;
}

vector<int> solve() {
    int n, m, x, y, p;
    cin >> n >> m >> x >> y >> p;
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<int> cmd;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < p; i++) {
        int temp; cin >> temp;
        cmd.push_back(temp);
    }
    
    pair<int, int> now = {x, y};
    vector<vector<int>> dice(4, vector<int>(3, 0));
    vector<int> ret;
    vector<int> dx = {0, 0, 0, -1, 1};
    vector<int> dy = {0, 1, -1, 0, 0};
    for(int k = 0; k < p; k++) {
        pair<int, int> next = {now.first+dx[cmd[k]], now.second+dy[cmd[k]]};
        if(!(0 <= next.first && next.first < n && 0 <= next.second && next.second < m)) continue;
        now = next; dice = rotate(dice, cmd[k]);
        if(board[now.first][now.second] == 0) {
            board[now.first][now.second] = dice[3][1];
        }
        else if(board[now.first][now.second] != 0) {
            dice[3][1] = board[now.first][now.second];
            board[now.first][now.second] = 0;
        }
        ret.push_back(dice[1][1]);
    }
    return ret;
}

int main() {
    FASTIO
    vector<int> sol = solve();
    for(int s : sol) cout << s << "\n";
}
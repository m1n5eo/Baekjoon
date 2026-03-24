#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000
#define MAX 33

int n, m, res, cnt;
vector<string> board(MAX);
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

void f(int x, int y, int c, int move) {
    if(c == cnt) {
        res = min(res, move);
        return;
    }

    for(int k = 0; k < 4; k++) {
        queue<pair<int, int>> save;
        int nx = x+dx[k], ny = y+dy[k], count = 0;
        if(!(0 <= nx && nx < n && 0 <= ny && ny < m) || board[nx][ny] == '*') continue;
        save.push({nx, ny});
        board[nx][ny] = '*';
        count += 1;
        while(0 <= nx+dx[k] && nx+dx[k] < n && 0 <= ny+dy[k] && ny+dy[k] < m && board[nx+dx[k]][ny+dy[k]] == '.') {
            nx = nx+dx[k];
            ny = ny+dy[k];
            save.push({nx, ny});
            board[nx][ny] = '*';
            count += 1;
        }
        f(nx, ny, c+count, move+1);
        while(!save.empty()) {
            pair<int, int> now = save.front();
            save.pop();
            board[now.first][now.second] = '.';
            count -= 1;
        }
    }
}

void solution() {
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '.') cnt += 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '.') {
                board[i][j] = '*';
                f(i, j, 1, 0);
                board[i][j] = '.';
            }
        }
    }
}

int main() {
    FASTIO
    int tc = 1;
    while(cin >> n >> m) {
        res = INF, cnt = 0;
        solution();
        cout << "Case " << tc++ << ": ";
        cout << (res != INF? res : -1) << "\n";
    }
}
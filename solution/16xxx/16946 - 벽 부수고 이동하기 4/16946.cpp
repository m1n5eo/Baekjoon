#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

int n, m, cnt, idx;
string str;
vector<vector<int>> board(MAX, vector<int>(MAX, 0));
vector<vector<int>> result(MAX, vector<int>(MAX, 0));
vector<int> counting(1, 0);

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int Find(int x, int y) {
    int rtn = 0;
    set<int> s;

    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        if(0 <= nx && nx < n && 0 <= ny && ny < m) {
            if(board[nx][ny] != -1) {
                s.insert(board[nx][ny]);
            }
        }
    }

    for(int index : s) {
        rtn += counting[index];
    }

    return (rtn+1)%10;
}

void dfs(int x, int y, int index) {
    board[x][y] = index;
    cnt += 1;

    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        if(0 <= nx && nx < n && 0 <= ny && ny < m) {
            if(board[nx][ny] == 0) {
                dfs(nx, ny, index);
            }
        }
    }
}

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> str;

        for(int j = 0; j < m; j++) {
            if(str[j] == '1') board[i][j] = -1;
            else if(str[j] == '0') board[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0) {
                cnt = 0;
                idx += 1;

                dfs(i, j, idx);

                counting.push_back(cnt);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == -1) result[i][j] = Find(i, j);
            else result[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << result[i][j];
        }
        cout << "\n";
    }
}
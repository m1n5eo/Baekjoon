#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

struct type {
    int x1, y1, x2, y2;
};

int n, a, b, c, d, cnt = 0;
vector<type> square(1, {-1, -1, -1, -1});
vector<int> parent(1, 0);
vector<vector<int>> board(MAX, vector<int>(MAX, 0));

int Find(int x) {
    if(x != parent[x]) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool Same(int x, int y) {
    x = Find(x);
    y = Find(y);

    return x == y? true : false;
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d;

        square.push_back({a+500, b+500, c+500, d+500});
        parent.push_back(i);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = square[k].x1; i <= square[k].x2; i++) {
            if(board[i][square[k].y1] != 0) Union(k, board[i][square[k].y1]);
            if(board[i][square[k].y2] != 0) Union(k, board[i][square[k].y2]);

            board[i][square[k].y1] = k;
            board[i][square[k].y2] = k;
        }

        for(int j = square[k].y1; j <= square[k].y2; j++) {
            if(board[square[k].x1][j] != 0) Union(k, board[square[k].x1][j]);
            if(board[square[k].x2][j] != 0) Union(k, board[square[k].x2][j]);

            board[square[k].x1][j] = k;
            board[square[k].x2][j] = k;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(Same(0, i) == false) {
            Union(0, i);
            cnt += 1;
        }
    }

    cout << (board[0+500][0+500] == 0? cnt : cnt-1);
}
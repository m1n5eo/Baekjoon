#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11

int n, blackSize, whiteSize, result1, result2, pan[MAX][MAX], cnt[MAX][MAX];
vector<pair<int, int>> black, white;

void visit(int x, int y, int idx) {
    if(idx == 0) {
        for(int i = 1; i < n; i++) {
            if(0 <= x+i && x+i < n && 0 <= y+i && y+i < n) cnt[x+i][y+i] += 1;
            if(0 <= x+i && x+i < n && 0 <= y-i && y-i < n) cnt[x+i][y-i] += 1;
            if(0 <= x-i && x-i < n && 0 <= y+i && y+i < n) cnt[x-i][y+i] += 1;
            if(0 <= x-i && x-i < n && 0 <= y-i && y-i < n) cnt[x-i][y-i] += 1;
        }
        
        cnt[x][y] += 1;
    }
    else if(idx == 1) {
        for(int i = 1; i < n; i++) {
            if(0 <= x+i && x+i < n && 0 <= y+i && y+i < n) cnt[x+i][y+i] -= 1;
            if(0 <= x+i && x+i < n && 0 <= y-i && y-i < n) cnt[x+i][y-i] -= 1;
            if(0 <= x-i && x-i < n && 0 <= y+i && y+i < n) cnt[x-i][y+i] -= 1;
            if(0 <= x-i && x-i < n && 0 <= y-i && y-i < n) cnt[x-i][y-i] -= 1;
        }
        
        cnt[x][y] -= 1;
    }
}

void bt1(int idx, int res) {
    result1 = max(result1, res);

    for(int i = idx+1; i < blackSize; i++) {
        int nx = black[i].first;
        int ny = black[i].second;

        if(cnt[nx][ny] == 0 && pan[nx][ny] == 1) {
            visit(nx, ny, 0);
            bt1(i, res+1);
            visit(nx, ny, 1);
        }
    }
}

void bt2(int idx, int res) {
    result2 = max(result2, res);

    for(int i = idx+1; i < whiteSize; i++) {
        int nx = white[i].first;
        int ny = white[i].second;

        if(cnt[nx][ny] == 0 && pan[nx][ny] == 1) {
            visit(nx, ny, 0);
            bt2(i, res+1);
            visit(nx, ny, 1);
        }
    }
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> pan[i][j];

            if(pan[i][j] == 1 && (i+j)%2 == 0) black.push_back({i, j});
            else if(pan[i][j] == 1 && (i+j)%2 == 1) white.push_back({i, j});
        }
    }

    blackSize = black.size();
    whiteSize = white.size();

    bt1(-1, 0);
    bt2(-1, 0);

    cout << result1+result2;
}
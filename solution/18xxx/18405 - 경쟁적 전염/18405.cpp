#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    int num, turn, x, y;
};

struct compare {
    bool operator()(type a, type b) {
        if(a.turn != b.turn) return a.turn > b.turn;
        else return a.num > b.num;
    }
};

int solution() {
    int n, m, s, idx, jdx;
    cin >> n >> m;
    vector<vector<int>> virus(n, vector<int>(n));
    priority_queue<type, vector<type>, compare> pq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> virus[i][j];
            if(virus[i][j] != 0) pq.push({virus[i][j], 0, i, j});
        }
    }
    cin >> s >> idx >> jdx;

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    while(!pq.empty()) {
        type now = pq.top(); pq.pop();
        for(int k = 0; k < 4; k++) {
            type next = {now.num, now.turn+1, now.x+dx[k], now.y+dy[k]};
            if(!(0 <= next.x && next.x < n && 0 <= next.y && next.y < m)) continue;
            else if(virus[next.x][next.y] != 0) continue;
            else if(next.turn > s) continue;
            pq.push(next);
            virus[next.x][next.y] = next.num;
        }
    }
    return virus[idx-1][jdx-1];
}

int main() {
    FASTIO
    cout << solution();
}
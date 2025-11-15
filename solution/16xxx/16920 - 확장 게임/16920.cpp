#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

struct type {
    int x, y, turn, idx, cnt;
};

struct compare {
    bool operator()(type a, type b) {
        if(a.turn != b.turn) return a.turn > b.turn;
        else if(a.idx != b.idx) return a.idx > b.idx;
        else return a.cnt > b.cnt;
    }
};

deque<int> solve() {
    int n, m, player;
    vector<int> move(1, 0);
    vector<vector<int>> gamepan(MAX, vector<int>(MAX, 0));
    cin >> n >> m >> player;
    for(int i = 1; i <= player; i++) {
        int temp; cin >> temp;
        move.push_back(temp);
    }
    for(int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for(int j = 0; j < m; j++) {
            if(temp[j] == '.') gamepan[i][j] = 0;
            else if(temp[j] == '#') gamepan[i][j] = -1;
            else gamepan[i][j] = temp[j]-'0';
        }
    }

    priority_queue<type, vector<type>, compare> bfs;
    for(int k = 1; k <= player; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(gamepan[i][j] == k) {
                    bfs.push({i, j, 0, k, 0});
                }
            }
        }
    }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    while(!bfs.empty()) {
        type now = bfs.top();
        bfs.pop();
        for(int k = 0; k < 4; k++) {
            type next;
            next.x = now.x+dx[k];
            next.y = now.y+dy[k];
            next.turn = (now.cnt+1 < move[now.idx]? now.turn : now.turn+1);
            next.idx = now.idx;
            next.cnt = (now.cnt+1 < move[now.idx]? now.cnt+1 : 0);
            if(0 <= next.x & next.x < n && 0 <= next.y && next.y < m) {
                if(gamepan[next.x][next.y] == 0) {
                    gamepan[next.x][next.y] = next.idx;
                    bfs.push(next);
                }
            }
        }
    }

    deque<int> ret(player+1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(gamepan[i][j] > 0) {
                ret[gamepan[i][j]] += 1;
            }
        }
    }
    ret.pop_front();
    return ret;
}

int main() {
    FASTIO
    deque<int> sol = solve();
    for(int s : sol) cout << s << " ";
}
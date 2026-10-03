#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11111

struct type {
    int speed, direction, length, idx;
};

int n, m, ret = 0;
queue<pair<pair<int, int>, type>> shark;
vector<bool> del(MAX, true);
vector<int> dx = {0, -1, 1, 0, 0};
vector<int> dy = {0, 0, 0, 1, -1};

pair<pair<int, int>, int> go(pair<int, int> coordinate, int dir, int spd) {
    if(dir == 1 || dir == 2) spd %= (n-1)*2;
    else if(dir == 3 || dir == 4) spd %= (m-1)*2;
    while(spd--) {
        coordinate = {coordinate.first+dx[dir], coordinate.second+dy[dir]};
        if(!(1 <= coordinate.first && coordinate.first <= n && 1 <= coordinate.second && coordinate.second <= m)) {
            if(dir == 1) dir = 2;
            else if(dir == 2) dir = 1;
            else if(dir == 3) dir = 4;
            else if(dir == 4) dir = 3;
            coordinate = {coordinate.first+dx[dir]*2, coordinate.second+dy[dir]*2};
        }
    }
    return {coordinate, dir};
}

vector<vector<type>> catch_shark(vector<vector<type>> sea, int people) {
    for(int i = 1; i <= n; i++) {
        if(sea[i][people].idx != -1) {
            del[sea[i][people].idx] = false;
            ret += sea[i][people].length;
            sea[i][people] = {-1, -1, -1, -1};
            break;
        }
    }
    return sea;
}

vector<vector<type>> move_shark(vector<vector<type>> sea) {
    vector<vector<type>> ret(n+1, vector<type>(m+1, {-1, -1, -1, -1}));
    int shark_size = shark.size();
    for(int _ = 0; _ < shark_size; _++) {
        pair<pair<int, int>, type> now = shark.front();
        shark.pop();

        if(del[now.second.idx] == false) continue;   
                
        pair<int, int> next = {now.first.first, now.first.second};
        type status = sea[now.first.first][now.first.second];
        pair<pair<int, int>, int> g = go(next, status.direction, status.speed);
        next = g.first; status.direction = g.second;

        if(ret[next.first][next.second].idx == -1) {
            ret[next.first][next.second] = status;
            shark.push({next, status});
        }
        else if(ret[next.first][next.second].length < status.length) {
            del[ret[next.first][next.second].idx] = false;
            ret[next.first][next.second] = status;
            shark.push({next, status});
        }
        else if(ret[next.first][next.second].length >= status.length) {
            del[status.idx] = false;
        }
    }
    return ret;
}

int solve() {
    int k;
    cin >> n >> m >> k;
    vector<vector<type>> sea(n+1, vector<type>(m+1, {-1, -1, -1, -1}));
    for(int i = 0; i < k; i++) {
        int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
        sea[r][c] = {s, d, z, i};
        shark.push({{r, c}, {s, d, z, i}});
    }

    for(int people = 1; people <= m; people++) {
        sea = catch_shark(sea, people);
        sea = move_shark(sea);
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
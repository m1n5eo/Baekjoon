#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define INF 1e9
#define MAX 55

struct type {
    int x, y, count;
};

int n, m, cnt = 3, result = INF;
string str;
vector<vector<int>> house(MAX, vector<int>(MAX, 0));
vector<vector<int>> dist(8, vector<int>(8, 0));
vector<pii> point(8, {0, 0});

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void backtracking(int c, vector<int> v, vector<bool> check) {
    if(c == cnt-2) {
        int total = 0;
        v[0] = 1, v[c] = 2;
        
        for(int i = 0; i < c; i++) {
            total += dist[v[i]][v[i+1]];
        }

        result = min(result, total);
        return;
    }

    for(int i = 3; i < cnt; i++) {
        if(check[i] == false) {
            check[i] = true;
            v[c] = i;
            backtracking(c+1, v, check);
            check[i] = false;
            v[c] = 0;
        }
    }
}

int search(int p, int q) {
    vector<vector<bool>> visit(MAX, vector<bool>(MAX, false));
    queue<type> bfs;

    bfs.push({point[p].first, point[p].second, 0});
    visit[point[p].first][point[p].second] = true;

    while(bfs.size()) {
        type now = bfs.front();
        bfs.pop();

        for(int k = 0; k < 4; k++) {
            type next = {now.x+dx[k], now.y+dy[k], now.count+1};

            if(0 <= next.x && next.x < n && 0 <= next.y && next.y < m) {
                if(visit[next.x][next.y] == false && house[next.x][next.y] != 9) {
                    if(house[next.x][next.y] == q) {
                        return next.count;
                    }

                    bfs.push({next.x, next.y, next.count});
                    visit[next.x][next.y] = true;
                }
            }
        }
    }
}

int main() {
    FASTIO

    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        cin >> str;

        for(int j = 0; j < m; j++) {
            if(str[j] == '#') house[i][j] = 9;
            else if(str[j] == '.') house[i][j] = 0;
            else if(str[j] == 'S') {
                house[i][j] = 1;
                point[1] = {i, j};
            }
            else if(str[j] == 'E') {
                house[i][j] = 2;
                point[2] = {i, j};
            }
            else if(str[j] == 'X') {
                house[i][j] = cnt;
                point[cnt] = {i, j};
                cnt += 1;
            }
        }
    }

    for(int i = 1; i < cnt; i++) {
        for(int j = i+1; j < cnt; j++) {
            int d = search(i, j);

            dist[i][j] = d;
            dist[j][i] = d;
        }
    }

    backtracking(1, vector<int>(7, 0), vector<bool>(8, false));

    cout << result;
}
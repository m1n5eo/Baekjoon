#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

struct type {
    pair<int, int> start, end;
    int time;
};

string solve(int w, int h) {
    int g, m;
    vector<vector<int>> pan(w, vector<int>(h, 0));
    vector<type> hole;
    cin >> g;
    for(int i = 0; i < g; i++) {
        int a, b; cin >> a >> b;
        pan[a][b] = -1;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x1, y1, x2, y2, t; cin >> x1 >> y1 >> x2 >> y2 >> t;
        hole.push_back({{x1, y1}, {x2, y2}, t});
        pan[x1][y1] = 1;
    }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int x = 0; x < w; x++) {
        for(int y = 0; y < h; y++) {
            if(pan[x][y] == -1 || pan[x][y] == 1 || (x == w-1 && y == h-1)) continue;
            for(int k = 0; k < 4; k++) {
                int nx = x+dx[k], ny = y+dy[k];
                if(0 <= nx && nx < w && 0 <= ny && ny < h) {
                    if(pan[nx][ny] == -1) continue;
                    hole.push_back({{x, y}, {nx, ny}, 1});
                }
            }
        }
    }

    // cout << "\n" << "hole" << "\n";
    // for(type ho : hole) {
    //     cout << ho.start.first << " " << ho.start.second << " ";
    //     cout << ho.end.first << " " << ho.end.second << " ";
    //     cout << ho.time << "\n";
    // }
    // cout << "\n";

    bool cycle = false;
    int n = w*h; m = hole.size();
    vector<vector<int>> dist(w, vector<int>(h, INF));
    dist[0][0] = 0;
    for(int round = 0; round < n; round++) {
        for(int i = 0; i < m; i++) {
            pair<int, int> s = hole[i].start, e = hole[i].end; int t = hole[i].time;
            if(dist[s.first][s.second] != INF && dist[e.first][e.second] > dist[s.first][s.second] + t) {
                dist[e.first][e.second] = dist[s.first][s.second] + t;
                if(round == n-1) cycle = true;
            }
        }
    }

    if(cycle == true) return "Never";
    else if(dist[w-1][h-1] == INF) return "Impossible";
    else return to_string(dist[w-1][h-1]);
}

int main() {
    FASTIO
    int w, h;
    while(cin >> w >> h) {
        if(w == 0 && h == 0) break;
        cout << solve(w, h) << "\n";
    }
}
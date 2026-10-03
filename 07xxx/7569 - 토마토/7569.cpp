#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    int x, y, z;
};

int main() {
    FASTIO

    int n, m, h, before = 0, after = 0;
    int dx[6] = {-1, 1, 0, 0, 0, 0},
        dy[6] = {0, 0, -1, 1, 0, 0},
        dz[6] = {0, 0, 0, 0, -1, 1};

    cin >> m >> n >> h;

    vector<vector<vector<int>>> box(n+1, vector<vector<int>>(m+1, vector<int>(h+1, 0)));
    vector<vector<vector<bool>>> visit(n+1, vector<vector<bool>>(m+1, vector<bool>(h+1, false)));
    queue<type> bfs;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> box[j][k][i];

                if(box[j][k][i] == 0) before += 1;
                else if(box[j][k][i] == 1) {
                    bfs.push({j, k, i});
                    visit[j][k][i] = true;
                }
            }
        }
    }

    int result = 0;

    while(bfs.size()) {
        int bfs_size = bfs.size();
        result += 1;

        for(int _ = 0; _ < bfs_size; _++) {
            type now = bfs.front();
            bfs.pop();

            for(int k = 0; k < 6; k++) {
                type next = {now.x+dx[k], now.y+dy[k], now.z+dz[k]};

                if(0 <= next.x && next.x < n && 0 <= next.y && next.y < m && 0 <= next.z && next.z < h && box[next.x][next.y][next.z] == 0) {
                    bfs.push(next);
                    box[next.x][next.y][next.z] = 1;
                    after += 1;
                }
            }
        }
    }

    if(before == after) cout << result-1;
    else cout << -1;
}
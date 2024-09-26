#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct coordinate {
    int x, y;
};

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    FASTIO

    while(true) {
        int n, m;

        cin >> m >> n;

        if(n == 0 && m == 0) {
            break;
        }

        vector<vector<int>> map(n+1, vector<int>(m+1, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> map[i][j];
            }
        }

        int cnt = 0;
        vector<vector<bool>> check(n+1, vector<bool>(m+1, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] == 1 && check[i][j] == false) {
                    queue<coordinate> bfs;
                    bfs.push({i, j});
                    check[i][j] = true;
                    cnt += 1;
                    
                    while(bfs.size()) {
                        coordinate now = bfs.front();
                        bfs.pop();

                        for(int k = 0; k < 8; k++) {
                            coordinate next = {now.x+dx[k], now.y+dy[k]};

                            if(0 <= next.x && next.x < n && 0 <= next.y && next.y < m) {
                                if(map[next.x][next.y] == 1 && check[next.x][next.y] == false) {
                                    bfs.push({next.x, next.y});
                                    check[next.x][next.y] = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << cnt << "\n";
    }
}
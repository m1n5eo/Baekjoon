#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

int n, m, boundary, result;
int R[MAX][MAX], G[MAX][MAX], B[MAX][MAX];
bool map[MAX][MAX], visit[MAX][MAX];
queue<pair<int, int>> bfs;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> R[i][j] >> G[i][j] >> B[i][j];
        }
    }

    cin >> boundary;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(R[i][j]+G[i][j]+B[i][j] >= boundary*3) map[i][j] = true;
            else map[i][j] = false;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == true) {
                bfs.push({i, j});

                map[i][j] = false;
                result += 1;

                while(bfs.size()) {
                    int x = bfs.front().first;
                    int y = bfs.front().second;

                    bfs.pop();

                    for(int k = 0; k < 4; k++) {
                        int nx = x+dx[k];
                        int ny = y+dy[k];

                        if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                            if(map[nx][ny] == true) {
                                bfs.push({nx, ny});

                                map[nx][ny] = false;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << result;

    return 0;
}
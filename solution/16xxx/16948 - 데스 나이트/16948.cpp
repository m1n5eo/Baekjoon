#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 222

struct type {
    int _x, _y, _cnt;
};

int n, x1, y1, x2, y2;
queue<type> bfs;
bool check[MAX][MAX];

int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};

int main() {
    FASTIO
    
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;

    bfs.push({x1, y1, 0});
    check[x1][y1] = true;

    while(bfs.size()) {
        int x = bfs.front()._x;
        int y = bfs.front()._y;
        int cnt = bfs.front()._cnt;

        bfs.pop();

        for(int k = 0; k < 6; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];

            if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                if(nx == x2 && ny == y2) {
                    cout << cnt+1;
                    return 0;
                }
                else if(check[nx][ny] == false) {
                    bfs.push({nx, ny, cnt+1});
                    check[nx][ny] = true;
                }
            }
        }
    }

    cout << -1;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

struct type {
    int x, y;
};

int n, m, result = 0;
vector<vector<int>> donut(MAX, vector<int>(MAX, 0));

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> donut[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(donut[i][j] == 0) {
                result += 1;

                queue<type> bfs;
                bfs.push({i, j});

                while(bfs.size()) {
                    type now = bfs.front();
                    bfs.pop();

                    for(int k = 0; k < 4; k++) {
                        type next = {(now.x+dx[k]+n)%n, (now.y+dy[k]+m)%m};

                        if(donut[next.x][next.y] == 0) {
                            donut[next.x][next.y] = 1;
                            bfs.push(next);
                        }
                    }
                }
            }
        }
    }

    cout << result;
}
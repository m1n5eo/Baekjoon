#include <iostream>
#include <algorithm>
using namespace std;

int tetromino_x[22][4] = {{0, 0, 0, 0}, {0, 1, 2, 3}, {0, 0, 1, 1}, {0, 1, 2, 2}, {0, 1, 0, 0}, {0, 0, 1, 2}, {0, 0, 0, -1}, {0, 1, 2, 2}, {0, 1, 1, 1}, {0, 0, 1, 2}, {0, 0, 0, 1}, {0, 1, 1, 2}, {1, 1, 0, 0}, {0, 1, 1, 2}, {0, 0, 1, 1}, {0, 0, 0, 1}, {-1, 0, 1, 0}, {0, 0, 0, -1}, {-1, 0, 1, 0}};
int tetromino_y[22][4] = {{0, 1, 2, 3}, {0, 0, 0, 0}, {0, 1, 0, 1}, {0, 0, 0, 1}, {0, 0, 1, 2}, {0, 1, 1, 1}, {0, 1, 2, 2}, {0, 0, 0, -1}, {0, 0, 1, 2}, {0, 1, 0, 0}, {0, 1, 2, 2}, {0, 0, 1, 1}, {0, 1, 1, 2}, {1, 1, 0, 0}, {0, 1, 1, 2}, {-1, 0, 1, 0}, {0, 0, 0, -1}, {-1, 0, 1, 0}, {0, 0, 0, 1}};

int n, m, res;
int paper[555][555];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 19; k++) {
                int sum = 0;
                for(int l = 0; l < 4; l++) {
                    int x = i+tetromino_x[k][l], y = j+tetromino_y[k][l];
                    
                    if(0 <= x && x < n && 0 <= y && y < m) {
                        sum += paper[x][y];
                        if(l == 3) {
                            res = max(res, sum);
                        }
                    }
                    else break;
                }
            }
        }
    }

    cout << res;

    return 0;
}
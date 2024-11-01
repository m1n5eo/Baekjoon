#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 333

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, r;
vector<vector<int>> v(MAX, vector<int>(MAX, 0));

int main() {
    FASTIO

    cin >> n >> m >> r;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for(int rotation = 0; rotation < r; rotation++) {
        vector<vector<int>> next(MAX, vector<int>(MAX, 0));

        for(int k = 0; k < min(n, m)/2; k++) {
            int sw = 0, x = k, y = k;
            
            while(true) {
                int nx = x+dx[sw], ny = y+dy[sw];

                if(!(k <= nx && nx < n-k && k <= ny && ny < m-k)) {
                    sw = (sw+1)%4;
                    nx = x+dx[sw], ny = y+dy[sw];
                }

                next[nx][ny] = v[x][y];
                x = nx, y = ny;

                if(nx == k && ny == k) {
                    break;
                }
            }
        }

        v = next;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111

int main() {
    FASTIO

    int n, a, b, m, kinship[MAX][MAX];

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            kinship[i][j] = 0;
        }
    }

    cin >> n;
    cin >> a >> b;
    cin >> m;

    for(int i = 0; i < m; i++) {
        int x, y;

        cin >> x >> y;

        kinship[x][y] = 1;
        kinship[y][x] = 1;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(k == i || i == j || j == k) continue;

                if(kinship[i][k] != 0 && kinship[k][j] != 0) {
                    if(kinship[i][j] == 0) {
                        kinship[i][j] = kinship[i][k]+kinship[k][j];
                    }
                }
            }
        }
    }

    if(kinship[a][b] == 0) cout << -1;
    else cout << kinship[a][b];
}
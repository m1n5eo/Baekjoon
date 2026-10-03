#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, m;

    cin >> n >> m;

    int a, b;
    vector<vector<vector<bool>>> v(2, vector<vector<bool>>(n+1, vector<bool>(n+1, false)));

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b;

        v[0][a][b] = true;
        v[1][b][a] = true;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j || j == k || k == i) {
                    continue;
                }

                for(int t = 0; t < 2; t++) {
                    if(v[t][i][k] && v[t][k][j]) {
                        v[t][i][j] = true;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        int cnt = 0;

        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            else if(!v[0][i][j] && !v[1][i][j]) {
                cnt += 1;
            }
        }

        cout << cnt << "\n";
    }
}
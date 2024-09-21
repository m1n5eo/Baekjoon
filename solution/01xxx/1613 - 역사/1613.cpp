#include <bits/stdc++.h>
using namespace std;

int history[401][401];

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, m, a, b, k;

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        history[a][b] = -1;
        history[b][a] = 1;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(history[i][k] == 1 && history[k][j] == 1) history[i][j] = 1;
                else if(history[i][k] == -1 && history[k][j] == -1) history[i][j] = -1;
            }
        }
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        cout << history[a][b] << "\n";
    }
}
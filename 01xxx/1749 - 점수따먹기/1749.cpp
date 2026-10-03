#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

int solution() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gamepan(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> gamepan[i][j];
            gamepan[i][j] += gamepan[i-1][j] + gamepan[i][j-1] - gamepan[i-1][j-1];
        }
    }

    int ret = -INF;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int x = 0; x < i; x++) {
                for(int y = 0; y < j; y++) {
                    ret = max(ret, gamepan[i][j] - gamepan[x][j] - gamepan[i][y] + gamepan[x][y]);
                }
            }
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solution();
}
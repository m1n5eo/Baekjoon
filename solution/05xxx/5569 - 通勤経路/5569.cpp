#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MOD 100000

int solution() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> route(n, vector<vector<int>>(m, vector<int>(4)));

    for(int i = 0; i < n; i++) route[i][0][0] = 1;
    for(int i = 0; i < m; i++) route[0][i][1] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            route[i][j][0] = (route[i][j][0] + route[i-1][j][0] + route[i-1][j][2]) % MOD;
            route[i][j][1] = (route[i][j][1] + route[i][j-1][1] + route[i][j-1][3]) % MOD;
            route[i][j][2] = (route[i][j][2] + route[i-1][j][1]) % MOD;
            route[i][j][3] = (route[i][j][3] + route[i][j-1][0]) % MOD;
        }
    }
    return (route[n-1][m-1][0] + route[n-1][m-1][1] + route[n-1][m-1][2] + route[n-1][m-1][3]) % MOD;
}

int main() {
    FASTIO
    cout << solution();
}
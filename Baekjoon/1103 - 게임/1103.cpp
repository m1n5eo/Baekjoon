#include <iostream>
#include <string>
using namespace std;

int n, m;
int map[55][55], dp[55][55];
bool visited[55][55];
string str;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y) {
    if(!(0 <= x && x < n && 0 <= y && y < m)) return 0;
    else if(map[x][y] == -1) return 0;
    else if(visited[x][y] == true) {
        cout << -1;
        exit(0);
    }
    else if(dp[x][y] != -1) return dp[x][y];

    visited[x][y] = true;
    dp[x][y] = 0;

    for(int k = 0; k < 4; k++) {
        int nx = x+(dx[k]*map[x][y]);
        int ny = y+(dy[k]*map[x][y]);

        dp[x][y] = max(dp[x][y], dfs(nx, ny)+1);
    }

    visited[x][y] = false;
    
    return dp[x][y];
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            if(str[j] == 'H') map[i][j] = -1;
            else map[i][j] = str[j]-'0';
            
            dp[i][j] = -1;
        }
    }

    int result = dfs(0, 0);
    cout << result;
}
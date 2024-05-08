#include <iostream>
using namespace std;

int n, m, a, b;
bool computer[111][111], visited[111];

void dfs(int idx) {
    if(visited[idx] == true) return;

    visited[idx] = true;

    for(int j = 1; j <= n; j++) {
        if(computer[idx][j] == true) {
            dfs(j);
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        computer[a][b] = true;
        computer[b][a] = true;
    }

    for(int i = 1; i <= n; i++) {
        if(computer[1][i] == true) {
            dfs(i);
        }
    }

    int cnt = 0;
    
    for(int i = 2; i <= n; i++) {
        if(visited[i] == true) cnt += 1;
    }

    cout << cnt;

    return 0;
}
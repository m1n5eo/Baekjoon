#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000
#define MAX 55

int n, m;
vector<vector<int>> v(MAX, vector<int>(MAX, 0));

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void dfs(int i, int j, int dist) {
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    else if(v[i][j] == -1 && dist != 0) return;
    else if(v[i][j] != 0 && v[i][j] != -1 && dist >= v[i][j]) return;

    if(v[i][j] != -1) {
        v[i][j] = dist;
    }
    
    for(int k = 0; k < 8; k++) {
        int nx = i+dx[k];
        int ny = j+dy[k];
        
        dfs(nx, ny, dist+1);
    }
}

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];

            if(v[i][j] == 1) {
                v[i][j] = -1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == -1) {
                dfs(i, j, 0);
            }
        }
    }

    int result = -INF;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            result = max(v[i][j], result);
        }
    }
    
    cout << result;
}
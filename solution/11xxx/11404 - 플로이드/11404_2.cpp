#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1e9
#define MAX 111

int n, m, dist[MAX][MAX];

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        
        if(dist[a][b] == 0) dist[a][b] = d;
        else dist[a][b] = min(dist[a][b], d);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j && dist[i][j] == 0) {
                dist[i][j] = INF;
            }
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist[i][j] == INF) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
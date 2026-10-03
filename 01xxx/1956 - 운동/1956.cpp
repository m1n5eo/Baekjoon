#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 444
#define INF 1e9

int n, m, dist[MAX][MAX];

int main() {
    FASTIO

    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;

        dist[a][b] = d;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][k] != 0 && dist[k][j] != 0) {
                    if(dist[i][j] == 0) dist[i][j] = dist[i][k]+dist[k][j];
                    else dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    int result = -INF;
    bool check = false;

    for(int i = 1; i <= n; i++) {
        if(dist[i][i] != 0) {
            if(result == -INF) result = dist[i][i];
            else result = min(result, dist[i][i]);
            
            check = true;
        }
    }

    if(check == false) cout << -1;
    else cout << result;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 222

int n, m, dist[MAX][MAX];
vector<int> v[MAX][MAX];

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;

        if(dist[a][b] == 0 || (dist[a][b] != 0 && dist[a][b] > d)) {
            dist[a][b] = d;

            v[a][b].push_back(a);
            v[a][b].push_back(b);
            
            dist[b][a] = d;

            v[b][a].push_back(b);
            v[b][a].push_back(a);
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i != j && dist[i][k] != 0 && dist[k][j] != 0) {
                    if(dist[i][j] == 0) {
                        dist[i][j] = dist[i][k]+dist[k][j];
                        
                        for(int t = 0; t < v[i][k].size(); t++) v[i][j].push_back(v[i][k][t]);
                        for(int t = 1; t < v[k][j].size(); t++) v[i][j].push_back(v[k][j][t]);
                    }
                    else {
                        if(dist[i][j] > dist[i][k]+dist[k][j]) {
                            dist[i][j] = dist[i][k]+dist[k][j];
                            
                            v[i][j].clear();

                            for(int t = 0; t < v[i][k].size(); t++) v[i][j].push_back(v[i][k][t]);
                            for(int t = 1; t < v[k][j].size(); t++) v[i][j].push_back(v[k][j][t]);
                        }
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(v[i][j].size() == 0) cout << "-" << " ";
            else cout << v[i][j][1] << " ";
        }
        cout << "\n";
    }
}
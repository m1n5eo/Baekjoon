#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000

int main() {
    FASTIO
    
    int n, m, a, b, c;

    cin >> n >> m;

    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    vector<vector<int>> cost(n+1, vector<int>(3, INF));
    vector<vector<bool>> visit(n+1, vector<bool>(3, false));

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    cin >> a >> b;

    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        cost[i][0] = dist[1][i];
        cost[i][1] = dist[a][i];
        cost[i][2] = dist[b][i];
    }

    visit[1][0] = true;
    visit[a][1] = true;
    visit[b][2] = true;

    for(int k = 0; k < 3; k++) {
        for(int _ = 0; _ < n; _++) {
            int small = INF, next = 0;

            for(int i = 1; i <= n; i++) {
                if(visit[i][k] == false && cost[i][k] <= small) {
                    small = cost[i][k];
                    next = i;
                }
            }

            if(small == INF) continue;

            visit[next][k] = true;

            for(int i = 1; i <= n; i++) {
                if(visit[i][k] == false) {
                    if(cost[next][k] + dist[next][i] < cost[i][k]) {
                        cost[i][k] = cost[next][k] + dist[next][i];
                    }
                }
            }
        }
    }

    int result = INF;

    if(cost[a][0] != INF && cost[b][1] != INF && cost[n][2] != INF) result = min(cost[a][0] + cost[b][1] + cost[n][2], result);
    if(cost[b][0] != INF && cost[a][2] != INF && cost[n][1] != INF) result = min(cost[b][0] + cost[a][2] + cost[n][1], result);
    
    if(result != INF) cout << result;
    else cout << -1;
}
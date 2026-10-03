#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000

int main() {
    FASTIO
    
    int n, m, a, b, c;

    cin >> n >> m;

    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    vector<int> cost(n+1, INF);
    vector<bool> visit(n+1, false);

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b >> c;

        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = min(c, dist[b][a]);
    }

    cin >> a >> b;

    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        cost[i] = dist[a][i];
    }

    visit[a] = true;

    for(int _ = 0; _ < n-2; _++) {
        int small = INF, next = 0;

        for(int i = 1; i <= n; i++) {
            if(cost[i] < small && visit[i] == false) {
                small = cost[i];
                next = i;
            }
        }

        visit[next] = true;

        for(int i = 1; i <= n; i++) {
            if(visit[i] == false) {
                if(cost[next] + dist[next][i] < cost[i]) {
                    cost[i] = cost[next] + dist[next][i];
                }
            }
        }
    }

    cout << cost[b];
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000

int main() {
    FASTIO
    
    int n, m, a, b;

    cin >> n;
    cin >> m;

    vector<vector<int>> bus(n+1, vector<int>(n+1, INF));
    vector<int> cost(n+1, INF);
    vector<bool> visit(n+1, false);
    vector<vector<int>> route(n+1, vector<int>(0));

    for(int _ = 0; _ < m; _++) {
        int s, e, c;
        cin >> s >> e >> c;

        bus[s][e] = min(bus[s][e], c);
    }

    cin >> a >> b;

    for(int i = 1; i <= n; i++) {
        bus[i][i] = 0;
        cost[i] = bus[a][i];

        route[i].push_back(a);
        if(i != a) route[i].push_back(i);
    }

    visit[a] = true;

    for(int _ = 0; _ < n-2; _++) {
        int small = INF, next = 0;
        
        for(int i = 1; i <= n; i++) {
            if(visit[i] == false && cost[i] <= small) {
                small = cost[i];
                next = i;
            }
        }

        visit[next] = true;

        for(int i = 1; i <= n; i++) {
            if(visit[i] == false) {
                if(cost[next] + bus[next][i] < cost[i]) {
                    cost[i] = cost[next] + bus[next][i];

                    route[i].clear();
                    for(int j = 0; j < route[next].size(); j++) route[i].push_back(route[next][j]);
                    route[i].push_back(i);
                }
            }
        }
    }

    cout << cost[b] << "\n";
    cout << route[b].size() << "\n";
    for(auto routes : route[b]) cout << routes << " ";
}
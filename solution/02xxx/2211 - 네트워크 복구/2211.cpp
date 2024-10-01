#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000
#define MAX 1111

int main() {
    FASTIO

    int n, m, a, b, c;
    vector<vector<int>> graph(MAX, vector<int>(MAX, INF));
    vector<int> cost(MAX, INF), parent(MAX, 1);
    vector<bool> visit(MAX, false);

    cin >> n >> m;

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b >> c;

        graph[a][b] = min(c, graph[a][b]);
        graph[b][a] = min(c, graph[b][a]);
    }

    for(int i = 1; i <= n; i++) {
        graph[i][i] = 0;
        cost[i] = graph[1][i];
    }

    visit[1] = true;

    for(int _ = 0; _ < n-2; _++) {
        int small = INF, next = 0;

        for(int i = 1; i <= n; i++) {
            if(visit[i] == false && cost[i] < small) {
                small = cost[i];
                next = i;
            }
        }

        visit[next] = true;

        for(int i = 1; i <= n; i++) {
            if(visit[i] == false) {
                if(cost[next] + graph[next][i] < cost[i]) {
                    cost[i] = cost[next] + graph[next][i];
                    parent[i] = next;
                }
            }
        }
    }

    cout << n-1 << "\n";

    for(int i = 2; i <= n; i++) {
        cout << parent[i] << " " << i << "\n";
    }
}
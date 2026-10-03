#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define MAX 1111
#define INF 1e9

int n, m, a, b, c;
vector<vector<pii>> graph(MAX, vector<pii>(0));
vector<bool> visit(MAX, false);

void dfs(int p, int q, int x, int dist) {    
    if(q == x) {
        cout << dist << "\n";
        return;
    }

    visit[x] = true;

    for(pii g : graph[x]) {
        if(visit[g.first] == false) {
            visit[g.first] = true;
            dfs(p, q, g.first, dist+g.second);
            visit[g.first] = false;
        }
    }
}

int main() {
    FASTIO

    cin >> n >> m;

    for(int _ = 0; _ < n-1; _++) {
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b;

        for(int i = 1; i <= n; i++) {
            visit[i] = false;
        }

        dfs(a, b, a, 0);
    }
}
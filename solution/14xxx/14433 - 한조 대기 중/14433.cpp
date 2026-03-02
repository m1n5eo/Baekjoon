#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 333

int n, m, k1, k2;
vector<vector<int>> graph;
vector<int> a, b;
vector<bool> visited;

bool dfs(int x) {
    visited[x] = true;
    for(int y : graph[x]) {
        if(b[y] == -1 || (!visited[b[y]] && dfs(b[y]))) {
            a[x] = y;
            b[y] = x;
            return true;
        }
    }
    return false;
}

int bipartite(int k) {
    graph = vector<vector<int>>(MAX);
    a = vector<int>(MAX, -1), b = vector<int>(MAX, -1);
    for(int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        graph[x-1].push_back(y-1);
    }

    int ret = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == -1) {
            visited = vector<bool>(MAX, false);
            if(dfs(i)) ret += 1;
        }
    }
    return ret;
}

void solution() {
    cin >> n >> m >> k1 >> k2;
    if(bipartite(k1) < bipartite(k2)) cout << "네 다음 힐딱이";
    else cout << "그만 알아보자";
}

int main() {
    FASTIO
    solution();
}
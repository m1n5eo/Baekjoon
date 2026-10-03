#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111
#define INF 1e9

struct type {
    int p, q, cost;
};

int result = -INF;
vector<int> parent;
vector<bool> check(MAX, false);
vector<vector<pair<int, int>>> graph(MAX, vector<pair<int, int>>(0));

void dfs(int x, int c) {
    check[x] = true;
    result = max(result, c);

    for(int i = 0; i < graph[x].size(); i++) {
        int nx = graph[x][i].first;
        int nc = graph[x][i].second;

        if(check[nx] == false) {
            dfs(nx, nc + c);
        }
    }
}

int Find(int x) {
    if(x == parent[x]) return parent[x];
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool Same(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return true;
    else return false;
}

bool compare(type x, type y) {
    return x.cost < y.cost;
}

int main() {
    FASTIO

    int n, m, a, b, c, min_cost = 0;
    vector<type> mst;

    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        parent.push_back(i);
    }

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b >> c;
        mst.push_back({a, b, c});
    }

    sort(mst.begin(), mst.end(), compare);

    for(int i = 0; i < m; i++) {
        if(Same(mst[i].p, mst[i].q) == false) {
            Union(mst[i].p, mst[i].q);
            min_cost += mst[i].cost;

            graph[mst[i].p].push_back({mst[i].q, mst[i].cost});
            graph[mst[i].q].push_back({mst[i].p, mst[i].cost});
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            check[j] = false;
        }

        dfs(i, 0);
    }

    cout << min_cost << " " << result;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

struct type {
    int p, q, cost;
};

vector<int> parent(MAX, 0);

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
    return x.cost > y.cost;
}

int main() {
    FASTIO

    int n, m, a, b, c, result = 0, count = 0;
    vector<type> mst;

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b >> c;
        mst.push_back({a, b, c});
    }

    sort(mst.begin(), mst.end(), compare);

    for(int i = 0; i < m; i++) {
        if(Same(mst[i].p, mst[i].q) == false) {
            Union(mst[i].p, mst[i].q);

            result += mst[i].cost;
            count += 1;
        }
    }

    if(count == n-1) cout << result;
    else cout << -1;
}
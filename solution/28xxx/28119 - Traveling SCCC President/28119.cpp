#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    int p, q, dist;
};

vector<int> parent;

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
    return x.dist < y.dist;
}

int main() {
    FASTIO

    int n, m, s, a, b, c, temp, result = 0;
    vector<type> mst;

    cin >> n >> m >> s;

    for(int i = 0; i <= n; i++) {
        parent.push_back(i);
    }

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b >> c;
        mst.push_back({a, b, c});
    }

    sort(mst.begin(), mst.end(), compare);

    for(int _ = 0; _ < n; _++) {
        cin >> temp;
    }

    for(int i = 0; i < m; i++) {
        if(Same(mst[i].p, mst[i].q) == false) {
            Union(mst[i].p, mst[i].q);
            result += mst[i].dist;
        }
    }

    cout << result;
}
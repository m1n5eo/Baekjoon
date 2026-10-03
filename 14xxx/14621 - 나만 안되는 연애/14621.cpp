#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

vector<int> parent(MAX, 0);

struct type {
    int p, q, dist;
};

bool compare(type x, type y) {
    return x.dist < y.dist;
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

int main() {
    FASTIO

    int n, m, a, b, d, cnt = 0, result = 0;
    char g;
    vector<int> gender(MAX, 0);
    vector<type> mst;

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> g;

        if(g == 'M') gender[i] = 0;
        else if(g == 'W') gender[i] = 1;

        parent[i] = i;
    }

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b >> d;
        mst.push_back({a, b, d});
    }

    sort(mst.begin(), mst.end(), compare);

    for(int i = 0; i < m; i++) {
        if(Same(mst[i].p, mst[i].q) == false && gender[mst[i].p] != gender[mst[i].q]) {
            Union(mst[i].p, mst[i].q);

            result += mst[i].dist;
            cnt += 1;
        }
    }

    if(cnt == n-1) cout << result;
    else cout << -1;
}
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 222222

struct type {
    int from, to;
    lli cost;
    int time;
};

vector<int> parent(MAX, 0);

int Find(int x) {
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x < y) parent[y] = x;
    else parent[x] = y;
}

bool Same(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return true;
    else return false;
}

bool compare(type x, type y) {
    if(x.cost != y.cost) return x.cost < y.cost;
    else return x.time < y.time;
}

int main() {
    FASTIO

    int n, m, p, q, t, cnt = 0;
    lli c;
    vector<type> mst;
    pair<int, lli> result = {0, 0};

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int _ = 0; _ < m; _++) {
        cin >> p >> q >> c >> t;
        mst.push_back({p, q, c, t});
    }

    sort(mst.begin(), mst.end(), compare);

    for(int i = 0; i < m; i++) {
        if(Same(mst[i].from, mst[i].to) == false) {
            Union(mst[i].from, mst[i].to);

            result = {max(mst[i].time, result.first), result.second+mst[i].cost};
            cnt += 1;
        }
    }

    if(cnt == n-1) cout << result.first << " " << result.second;
    else cout << -1;
}
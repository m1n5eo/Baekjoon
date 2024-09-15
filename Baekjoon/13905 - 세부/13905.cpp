#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1111111

struct type {
    int p, q, weight;
};

vector<int> parent;

int Find(int x) {
    if(x == parent[x]) return x;
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
    return x.weight > y.weight;
}

int main() {
    FASTIO

    int n, m, s, e, result = INF;

    cin >> n >> m;
    cin >> s >> e;

    for(int i = 0; i <= n; i++) {
        parent.push_back(i);
    }

    vector<type> mst;

    for(int _ = 0; _ < m; _++) {
        int _p, _q, _weight;
        cin >> _p >> _q >> _weight;

        mst.push_back({_p, _q, _weight});
    }

    sort(mst.begin(), mst.end(), compare);

    for(int i = 0; i < m; i++) {
        if(Same(s, e) == false) {
            Union(mst[i].p, mst[i].q);
            result = min(result, mst[i].weight);
        }
        else break;
    }

    if(Same(s, e) == true) cout << result;
    else cout << 0;
}
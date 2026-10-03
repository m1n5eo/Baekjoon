#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

struct type {
    int p, q, t;
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
    return x.t < y.t;
}

int main() {
    FASTIO

    int n, m, a, b, c, day = 1;
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
        if(mst[i].t == day && Same(mst[i].p, mst[i].q) == false) {
            Union(mst[i].p, mst[i].q);
            day += 1;
        }
    }

    cout << day;
}
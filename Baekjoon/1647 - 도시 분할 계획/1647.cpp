#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct type {
    int s, e, dist;
};

int n, m, a, b, d, result, erase;
vector<type> v;
vector<int> parent;

bool compare(type x, type y) {
    return x.dist < y.dist;
}

int Find(int x) {
    if(x == parent[x]) return x;

    int p = Find(parent[x]);
    parent[x] = p;

    return p;
}

bool isSame(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return true;
    else return false;
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        parent.push_back(i);
    }

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        v.push_back({a, b, d});
    }

    sort(v.begin(), v.end(), compare);

    int v_size = v.size();

    for(int i = 0; i < v_size; i++) {
        if(isSame(v[i].s, v[i].e) == false) {
            Union(v[i].s, v[i].e);
            result += v[i].dist;
            erase = v[i].dist;
        }
    }

    cout << result-erase;

    return 0;
}
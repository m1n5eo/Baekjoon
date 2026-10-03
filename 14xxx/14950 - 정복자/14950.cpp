#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct type {
    int s, e, dist;
};

int n, m, t, a, b, d, cnt, result;
vector<int> parent;
vector<type> v;

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

    cin >> n >> m >> t;
    
    for(int i = 0; i <= n; i++) {
        parent.push_back(i);
    }

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        if(a > b) {
            swap(a, b);
        }
        v.push_back({a, b, d});
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < m; i++) {
        if(isSame(v[i].s, v[i].e) == false) {
            Union(v[i].s, v[i].e);
            result += v[i].dist + (cnt*t);
            cnt += 1;
        }
    }

    cout << result;
}
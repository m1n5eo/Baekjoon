#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ulli unsigned long long int

struct type {
    ulli s, e, dist;
};

ulli n, m, a, b, d, result, total;
vector<ulli> parent;
vector<type> v;

bool compare(type x, type y) {
    return x.dist < y.dist;
}

ulli Find(ulli x) {
    if(x == parent[x]) return x;

    ulli p = Find(parent[x]);
    parent[x] = p;

    return p;
}

bool isSame(ulli x, ulli y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return true;
    else return false;
}

void Union(ulli x, ulli y) {
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

        if(a > b) {
            swap(a, b);
        }

        v.push_back({a, b, d});
        total += d;
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < m; i++) {
        if(isSame(v[i].s, v[i].e) == false) {
            Union(v[i].s, v[i].e);
            result += v[i].dist;
        }
    }

    for(int i = 1; i <= n; i++) {
        parent[i] = Find(i);
        if(parent[i] != 1) {
            cout << -1;
            exit(0);
        }
    }

    cout << total-result;
}
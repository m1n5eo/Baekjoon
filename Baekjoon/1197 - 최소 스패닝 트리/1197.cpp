#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define lli long long int
#define MAX 11111

struct type {
    int s, e, dist;
};

int n, m, a, b, d, result;
int parent[MAX];
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

    if(x < y) parent[y] = x;
    else parent[x] = y;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
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
            result += v[i].dist;
        }
    }

    cout << result;
}
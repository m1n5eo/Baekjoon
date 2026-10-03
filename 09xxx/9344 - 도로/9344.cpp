#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 11111

struct type {
    int s, e, cost;
};

int t, n, m, p, q, a, b, d;
int parent[MAX];

bool compare(type x, type y) {
    return x.cost < y.cost;
}

int Find(int x) {
    if(x == parent[x]) return x;

    int p = Find(parent[x]);
    parent[x] = p;

    return p;
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool isSame(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return true;
    else return false;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    for(int _ = 0; _ < t; _++) {
        vector<type> v;
        
        cin >> n >> m >> p >> q;

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            v.push_back({a, b, d});
        }

        sort(v.begin(), v.end(), compare);

        int v_size = v.size(), stop_point = 0;

        for(int i = 0; i < v_size && stop_point == 0; i++) {
            if(isSame(v[i].s, v[i].e) == false) {
                Union(v[i].s, v[i].e);
                if(min(v[i].s, v[i].e) == min(p, q) && max(v[i].s, v[i].e) == max(p, q)) {
                    stop_point = 1;
                    break;
                }
            }
        }

        if(stop_point == 0) cout << "NO\n";
        else cout << "YES\n";
    }
}
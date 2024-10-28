#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 1111

struct type {
    int p, q, w;
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
    return x.w > y.w;
}

int main() {
    FASTIO

    int n, m, k, a, b, c;
    vector<type> bridge;

    cin >> n >> m >> k;

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b >> c;
        bridge.push_back({a, b, c});
    }

    sort(bridge.begin(), bridge.end(), compare);

    for(int _ = 0; _ < k; _++) {
        vector<type> mst = bridge;
        int width;

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        cin >> a >> b;

        for(int i = 0; i < m; i++) {
            if(Same(mst[i].p, mst[i].q) == false) {
                Union(mst[i].p, mst[i].q);
                width = mst[i].w;
            }

            if(Same(a, b) == true) {
                break;
            }
        }

        cout << width << "\n";
    }
}
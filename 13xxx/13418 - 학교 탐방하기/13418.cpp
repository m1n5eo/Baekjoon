#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

struct type {
    int p, q, how;
};

vector<vector<int>> parent(MAX, vector<int>(2, 0));

int Find(int x, int idx) {
    if(x == parent[x][idx]) return parent[x][idx];
    else return parent[x][idx] = Find(parent[x][idx], idx);
}

void Union(int x, int y, int idx) {
    x = Find(x, idx);
    y = Find(y, idx);

    if(x > y) parent[x][idx] = y;
    else parent[y][idx] = x;
}

bool Same(int x, int y, int idx) {
    x = Find(x, idx);
    y = Find(y, idx);

    if(x == y) return true;
    else return false;
}

bool compare(type x, type y) {
    return x.how < y.how;
}

int main() {
    FASTIO

    int n, m, a, b, c, minimum = 0, maximum = 0;;
    vector<type> mst;

    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        parent[i] = {i, i};
    }

    cin >> a >> b >> c;

    Union(a, b, 0);
    Union(a, b, 1);

    if(c == 0) {
        maximum += 1;
        minimum += 1;
    }

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b >> c;
        mst.push_back({a, b, c});
    }

    sort(mst.begin(), mst.end(), compare);

    for(int i = 0; i <= m; i++) {
        if(Same(mst[i].p, mst[i].q, 0) == false) {
            Union(mst[i].p, mst[i].q, 0);

            if(mst[i].how == 0) {
                maximum += 1;
            }
        }
    }

    for(int i = m; i >= 0; i--) {
        if(Same(mst[i].p, mst[i].q, 1) == false) {
            Union(mst[i].p, mst[i].q, 1);

            if(mst[i].how == 0) {
                minimum += 1;
            }
        }
    }

    cout << maximum*maximum - minimum*minimum;
}
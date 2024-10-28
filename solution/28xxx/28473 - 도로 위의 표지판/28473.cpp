#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 222222

struct type {
    int p, q, num;
    lli cost; 
};

vector<int> parent;

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
    if(x.num != y.num) return x.num < y.num;
    else return x.cost < y.cost;
}

int main() {
    FASTIO

    int n, m, a, b, c, d, count = 0;
    lli sum = 0;
    vector<type> mst;
    vector<int> result;

    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        parent.push_back(i);
    }

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b >> c >> d;
        mst.push_back({a, b, c, d});
    }

    sort(mst.begin(), mst.end(), compare);
    
    for(int i = 0; i < m; i++) {
        if(Same(mst[i].p, mst[i].q) == false) {
            Union(mst[i].p, mst[i].q);

            result.push_back(mst[i].num);
            sum += mst[i].cost;
            count += 1;
        }
    }

    if(count == n-1) {
        for(auto res : result) cout << res;
        cout << " " << sum;
    }
    else cout << -1;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    int p, q;
    double dist;
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
    return x.dist < y.dist;
}

int main() {
    // FASTIO

    int n, m, cnt = 0;
    double c, total, result = 0;
    string temp, a, b;
    map<string, int> name;
    vector<type> mst;

    cin >> total;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp;

        parent.push_back(i);
        name.insert({temp, i});
    }

    cin >> m;

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b >> c;

        mst.push_back({name[a], name[b], c});
    }

    sort(mst.begin(), mst.end(), compare);

    for(int i = 0; i < m; i++) {
        if(Same(mst[i].p, mst[i].q) == false) {
            Union(mst[i].p, mst[i].q);
            
            result += mst[i].dist;
            cnt += 1;
        }
    }

    if(cnt == n-1 && total >= result) cout << "Need " << result << " miles of cable" << "\n";
    else cout << "Not enough cable";
}
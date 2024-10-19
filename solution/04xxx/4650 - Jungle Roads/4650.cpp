#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    int p, q, dist;
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
    FASTIO

    while(true) {
        int n, k, b, cnt = 0, result = 0;
        char now, a;
        vector<type> mst;

        cin >> n;

        if(n == 0) {
            break;
        }

        for(int i = 0; i < n; i++) {
            parent.push_back(i);
        }

        for(int _ = 0; _ < n-1; _++) {
            cin >> now >> k;

            for(int __ = 0; __ < k; __++) {
                cin >> a >> b;
                
                mst.push_back({now-'A', a-'A', b});
                cnt += 1;
            }
        }

        sort(mst.begin(), mst.end(), compare);

        for(int i = 0; i < cnt; i++) {
            if(Same(mst[i].p, mst[i].q) == false) {
                Union(mst[i].p, mst[i].q);
                result += mst[i].dist;
            }
        }

        cout << result << "\n";

        parent.clear();
        mst.clear();
    }
}
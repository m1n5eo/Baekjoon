#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

struct type {
    lli x1, y1, x2, y2;
};

bool compare(lli x, lli y) {
    return x < y;
}

int main() {
    FASTIO

    lli r, c, n, a, x, y;
    map<lli, type> m;
    vector<lli> v;

    cin >> r >> c;
    cin >> n;

    for(lli _ = 0; _ < n; _++) {
        cin >> a >> x >> y;

        if(m.find(a) == m.end()) {
            m.insert({a, {x, y, x, y}});
            v.push_back(a);
        }
        else {
            m[a].x1 = min(m[a].x1, x);
            m[a].y1 = min(m[a].y1, y);
            m[a].x2 = max(m[a].x2, x);
            m[a].y2 = max(m[a].y2, y);
        }
    }

    lli res1, res2 = 0;

    for(auto idx : v) {
        lli area = (m[idx].x2-m[idx].x1+1)*(m[idx].y2-m[idx].y1+1);

        if(area > res2 || (area == res2 && idx < res1)) {
            res1 = idx;
            res2 = area;
        }
    }

    cout << res1 << " " << res2;
}
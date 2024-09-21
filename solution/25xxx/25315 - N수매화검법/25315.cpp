#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

struct point {
    lli x, y;
};

struct type {
    point s, e;
    lli w;
};

int n;
vector<type> v;

bool compare(type a, type b) {
    return a.w < b.w;
}

lli ccw(point a, point b, point c) {
    lli CrossProduct = (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);

    if(CrossProduct < 0) return -1;
    else if(CrossProduct > 0) return 1;
    else return 0;
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        lli sx, sy, ex, ey, w;
        cin >> sx >> sy >> ex >> ey >> w;

        v.push_back({sx, sy, ex, ey, w});
    }

    sort(v.begin(), v.end(), compare);

    lli result = 0;

    for(int i = 0; i < n; i++) {
        lli m = 1;

        for(int j = i+1; j < n; j++) {
            lli ccw1 = ccw(v[i].s, v[i].e, v[j].s);
            lli ccw2 = ccw(v[i].s, v[i].e, v[j].e);

            lli ccw3 = ccw(v[j].s, v[j].e, v[i].s);
            lli ccw4 = ccw(v[j].s, v[j].e, v[i].e);

            if(ccw1*ccw2 < 0 && ccw3*ccw4 < 0) m += 1;
        }

        result += m*v[i].w;
    }

    cout << result;
}
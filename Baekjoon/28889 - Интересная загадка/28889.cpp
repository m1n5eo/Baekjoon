#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

struct type1 {
    lli x, y;
};

struct type2 {
    lli u, v, dist;
};

lli n;
vector<lli> parent;
vector<type1> point;
vector<type2> mst;

lli Find(lli a) {
    if(a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(lli a, lli b) {
    a = Find(a);
    b = Find(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

bool Same(lli a, lli b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

bool compare(type2 a, type2 b) {
    return a.dist < b.dist;
}

int main() {
    FASTIO

    cin >> n;

    for(lli i = 0; i < n; i++) {
        lli _x, _y;

        cin >> _x >> _y;

        point.push_back({_x, _y});
        parent.push_back(i);
    }

    for(lli i = 0; i < n; i++) {
        for(lli j = i+1; j < n; j++) {
            lli distance = (point[i].x-point[j].x)*(point[i].x-point[j].x) + (point[i].y-point[j].y)*(point[i].y-point[j].y);
            mst.push_back({i, j, distance});
        }
    }

    sort(mst.begin(), mst.end(), compare);

    lli mstSize = mst.size(), result = 0;

    for(lli i = 0; i < mstSize; i++) {
        if(Same(mst[i].u, mst[i].v) == false) {
            Union(mst[i].u, mst[i].v);
            result = max(result, mst[i].dist);
        }
    }

    cout << result;
}
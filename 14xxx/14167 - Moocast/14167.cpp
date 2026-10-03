#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 1111

struct type1 {
    int x, y;
};

struct type2 {
    int u, v;
    lli dist;
};

int n;
vector<int> parent(MAX, 0);
vector<type1> point;
vector<type2> mst;

int Find(int a) {
    if(a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

bool Same(int a, int b) {
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

    for(int i = 0; i < n; i++) {
        int _x, _y;

        cin >> _x >> _y;

        point.push_back({_x, _y});
        parent[i] = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            lli distance = ((point[i].x-point[j].x)*(point[i].x-point[j].x) + (point[i].y-point[j].y)*(point[i].y-point[j].y));
            mst.push_back({i, j, distance});
        }
    }

    sort(mst.begin(), mst.end(), compare);

    int mstSize = mst.size();
    lli result = 0;

    for(int i = 0; i < mstSize; i++) {
        if(Same(mst[i].u, mst[i].v) == false) {
            Union(mst[i].u, mst[i].v);
            result = max(result, mst[i].dist);
        }
    }

    cout << result;
}
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

#define ulli unsigned long long int
#define MAX 1111

struct type {
    int s, e;
    double dist;
};

int n, m, a, b, parent[MAX];
double result;
vector<type> v;
vector<pair<int, int>> point;

bool compare(type x, type y) {
    return x.dist < y.dist;
}

int Find(int x) {
    if(x == parent[x]) return x;

    int p = Find(parent[x]);
    parent[x] = p;

    return p;
}

bool isSame(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return true;
    else return false;
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    point.push_back({0, 0});
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        point.push_back({a, b});
    }

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        Union(a, b);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            double distance = pow(point[i].first-point[j].first, 2) + pow(point[i].second-point[j].second, 2);
            distance = sqrt(distance);
            
            v.push_back({i, j, distance});
        }
    }

    sort(v.begin(), v.end(), compare);

    int v_size = v.size();

    for(int i = 0; i < v_size; i++) {
        if(isSame(v[i].s, v[i].e) == false) {
            Union(v[i].s, v[i].e);
            result += v[i].dist;
        }
    }

    cout.precision(2);
    cout << fixed;
    cout << result;

    return 0;
}
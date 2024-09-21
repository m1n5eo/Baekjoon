#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct point {
    double x, y;
};

struct type {
    double s, e, dist;
};

int n;
double result;
vector<int> parent;
vector<point> v;
vector<type> tree;

bool compare(type a, type b) {
    return a.dist < b.dist;
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

    cin >> n;

    for(int i = 0; i < n; i++) {
        parent.push_back(i);
    }

    for(int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;

        v.push_back({a, b});
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            double distance = sqrt((v[i].x-v[j].x)*(v[i].x-v[j].x) + (v[i].y-v[j].y)*(v[i].y-v[j].y));
            tree.push_back({i, j, distance});
        }
    }

    sort(tree.begin(), tree.end(), compare);

    int tree_size = tree.size();

    for(int i = 0; i < tree_size; i++) {
        if(isSame(tree[i].s, tree[i].e) == false) {
            Union(tree[i].s, tree[i].e);
            result += tree[i].dist;
        }
    }

    cout.precision(2);
    cout << fixed;
    cout << result;
}
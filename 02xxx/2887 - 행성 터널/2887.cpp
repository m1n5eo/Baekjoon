#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100001
#define INF 2100000000

struct point {
    int x, y, z, idx;
};

struct type {
    int node1, node2, dist;
};

int n, result, parent[MAX];
vector<point> v;
vector<type> tree;

bool compare(type a, type b) {
    return a.dist < b.dist;
}

bool compare2(point a, point b) {
    return a.x < b.x;
}

bool compare3(point a, point b) {
    return a.y < b.y;
}

bool compare4(point a, point b) {
    return a.z < b.z;
}

int Find(int a) {
    if(a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
}

bool isSame(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        v.push_back({a, b, c, i});
        parent[i] = i;
    }

    sort(v.begin(), v.end(), compare2);

    for(int i = 1; i < n; i++) {
        int distance = INF;
        distance = min(distance, abs(v[i].x-v[i-1].x));
        distance = min(distance, abs(v[i].y-v[i-1].y));
        distance = min(distance, abs(v[i].z-v[i-1].z));

        tree.push_back({v[i].idx, v[i-1].idx, distance});
    }

    sort(v.begin(), v.end(), compare3);

    for(int i = 1; i < n; i++) {
        int distance = INF;
        distance = min(distance, abs(v[i].x-v[i-1].x));
        distance = min(distance, abs(v[i].y-v[i-1].y));
        distance = min(distance, abs(v[i].z-v[i-1].z));

        tree.push_back({v[i].idx, v[i-1].idx, distance});
    }

    sort(v.begin(), v.end(), compare4);

    for(int i = 1; i < n; i++) {
        int distance = INF;
        distance = min(distance, abs(v[i].x-v[i-1].x));
        distance = min(distance, abs(v[i].y-v[i-1].y));
        distance = min(distance, abs(v[i].z-v[i-1].z));

        tree.push_back({v[i].idx, v[i-1].idx, distance});
    }

    sort(tree.begin(), tree.end(), compare);

    int tree_size = tree.size();

    for(int i = 0; i < tree_size; i++) {
        if(isSame(tree[i].node1, tree[i].node2) == false) {
            Union(tree[i].node1, tree[i].node2);
            result += tree[i].dist;
        }
    }

    cout << result;
}
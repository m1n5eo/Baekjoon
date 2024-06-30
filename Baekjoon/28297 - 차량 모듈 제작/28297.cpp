#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111
#define PI 3.1415926535

struct point {
    int x, y, rad;
};

struct type {
    int p, q;
    double dist;
};

int n;
vector<int> parent;
vector<point> v;
vector<type> tree;

bool compare(type a, type b) {
    return a.dist < b.dist;
}

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

double calculate(int a, int b) {
    double circle1, circle2;

    double distance = sqrt((v[a].x-v[b].x)*(v[a].x-v[b].x)+(v[a].y-v[b].y)*(v[a].y-v[b].y));
    double length = sqrt(distance*distance-(v[a].rad-v[b].rad)*(v[a].rad-v[b].rad));
    double theta = acos(abs(v[a].rad-v[b].rad)/distance) * 180.0 / PI;

    if(v[a].rad < v[b].rad) {
        circle1 = 2*PI*v[a].rad*(2*theta/360.0);
        circle2 = 2*PI*v[b].rad*((360.0-2*theta)/360.0);
    }
    else {
        circle1 = 2*PI*v[a].rad*((360.0-2*theta)/360.0);
        circle2 = 2*PI*v[b].rad*(2*theta/360.0);
    }

    double result = length*2 + circle1 + circle2;

    return result;
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        parent.push_back(i);
    }

    for(int i = 0; i < n; i++) {
        int a, b, r;
        cin >> a >> b >> r;

        v.push_back({a, b, r});
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if((v[i].x-v[j].x)*(v[i].x-v[j].x)+(v[i].y-v[j].y)*(v[i].y-v[j].y) <= (v[i].rad+v[j].rad)*(v[i].rad+v[j].rad)) {
                if(Same(i, j) == false) {
                    Union(i, j);
                }
            }
            else if(Same(i, j) == false) {
                double temp = calculate(i, j); // i와 j의 벨트 거리
                tree.push_back({i, j, temp});
            }
        }
    }

    sort(tree.begin(), tree.end(), compare);

    int tree_size = tree.size();
    double result = 0;

    for(int i = 0; i < tree_size; i++) {
        if(Same(tree[i].p, tree[i].q) == false) {
            Union(tree[i].p, tree[i].q);
            result += tree[i].dist;
        }
    }

    cout.precision(6);
    cout << fixed;
    cout << result;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

struct type {
    int p, q, dist;
};

int n, temp;
vector<int> parent;
vector<type> mst;
vector<vector<int>> graph(MAX, vector<int>(0));

int Find(int x) {
    if(x != parent[x]) parent[x] = Find(parent[x]);
    return parent[x];
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

    return x == y? true : false;
}

bool compare1(type x, type y) {
    return x.dist < y.dist;
}

bool compare2(int x, int y) {
    return x < y;
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i <= n; i++) {
        parent.push_back(i);
    }

    for(int i = 1; i <= n-1; i++) {
        for(int j = i+1; j <= n; j++) {
            cin >> temp;
            mst.push_back({i, j, temp});
        }
    }

    sort(mst.begin(), mst.end(), compare1);
    
    for(int i = 0; i < n*(n-1)/2; i++) {
        if(Same(mst[i].p, mst[i].q) == false) {
            Union(mst[i].p, mst[i].q);

            graph[mst[i].p].push_back(mst[i].q);
            graph[mst[i].q].push_back(mst[i].p);
        }
    }

    for(int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), compare2);
        
        cout << graph[i].size() << " ";
        
        for(int g : graph[i]) {
            cout << g << " ";
        }

        cout << "\n";
    }
}
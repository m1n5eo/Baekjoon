#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000
#define MAX 222

struct type {
    int p, q, c;
};

vector<int> parent(MAX, 0);

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
    return x.c < y.c;
}

int main() {
    FASTIO

    int n, cnt = 0, cost = 0;
    pair<int, vector<pair<int, int>>> bridge = {0, vector<pair<int, int>>(0)};
    vector<vector<int>> graph(MAX, vector<int>(MAX, INF));
    vector<type> mst;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> graph[i][j];

            if(i < j) {
                if(graph[i][j] > 0) {
                    mst.push_back({i, j, graph[i][j]});
                    cnt += 1;
                }
                else if(graph[i][j] < 0) {
                    Union(i, j);
                    cost += (-graph[i][j]);
                }
            }
        }
    }

    sort(mst.begin(), mst.end(), compare);

    for(int i = 0; i < cnt; i++) {
        if(Same(mst[i].p, mst[i].q) == false) {
            Union(mst[i].p, mst[i].q);

            cost += mst[i].c;
            
            bridge.first += 1;
            bridge.second.push_back({mst[i].p, mst[i].q});
        }
    }
    
    cout << cost << " " << bridge.first << "\n";

    for(int i = 0; i < bridge.first; i++) {
        cout << bridge.second[i].first << " " << bridge.second[i].second << "\n";
    }
}
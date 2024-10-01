#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 555

struct type {
    int p, q, dist;
};

vector<int> parent(MAX*MAX, 0);

int Find(int x) {
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x > y) parent[y] = x;
    else parent[x] = y;
}

bool Same(int x, int y) {
    x = Find(x);
    y = Find(y);

    return x == y? true : false;
}

bool compare(type x, type y) {
    return x.dist < y.dist;
}

int main() {
    FASTIO

    int t;

    cin >> t;

    for(int tc = 0; tc < t; tc++) {
        int n, m, temp, result = 0;
        vector<type> graph;

        cin >> n >> m;

        for(int i = 0; i < n*m; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m-1; j++) {
                cin >> temp;
                graph.push_back({i*m+j, i*m+j+1, temp});
            }
        }

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < m; j++) {
                cin >> temp;
                graph.push_back({i*m+j, i*m+j+m, temp});
            }
        }

        sort(graph.begin(), graph.end(), compare);

        for(int i = 0; i < n*(m-1) + (n-1)*m; i++) {
            if(Same(graph[i].p, graph[i].q) == false) {
                Union(graph[i].p, graph[i].q);
                result += graph[i].dist;
            }
        }

        cout << result << "\n";
    }
}
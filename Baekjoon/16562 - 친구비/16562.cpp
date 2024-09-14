#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000

vector<int> parent(1, 0);

int Find(int x) {
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

int main() {
    FASTIO
    
    int n, m, k, a, b, temp, result = 0;
    vector<int> cost(1, 0), last(1, INF);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        cin >> temp;

        cost.push_back(temp);
        last.push_back(INF);
        parent.push_back(i);
    }

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b;
        Union(a, b);
    }

    for(int i = 1; i <= n; i++) {
        parent[i] = Find(i);
        
        if(last[parent[i]] == INF) {
            result += cost[i];
            last[parent[i]] = cost[i];
        }
        else if(last[parent[i]] != INF && last[parent[i]] > cost[i]) {
            result -= last[parent[i]] - cost[i];
            last[parent[i]] = cost[i];
        }
    }

    if(result <= k) cout << result;
    else cout << "Oh no";
}
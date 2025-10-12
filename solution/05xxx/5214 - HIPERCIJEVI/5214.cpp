#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int solve() {
    int n, m, k, hyper;
    cin >> n >> k >> m;
    vector<vector<int>> graph(n+m+1);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            cin >> hyper;
            graph[hyper].push_back(n+i+1);
            graph[n+i+1].push_back(hyper);
        }
    }

    // cout << "\n" << "graph" << "\n";
    // for(int i = 1; i < graph.size(); i++) {
    //     cout << i << " : ";
    //     for(int g : graph[i]) cout << g << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    queue<pair<int, int>> bfs;
    vector<bool> check(MAX*2, false);
    bfs.push({1, 0});
    check[1] = true;
    if(n == 1) return 1;
    while(!bfs.empty()) {
        pair<int, int> now = bfs.front();
        bfs.pop();
        // cout << now.first << " " << now.second << "\n";
        for(int g : graph[now.first]) {
            if(g == n) return now.second+1;
            else if(check[g] == false) {
                if(g > n) bfs.push({g, now.second+1});
                else bfs.push({g, now.second});
                check[g] = true;
            }
        }
    }
    return -1;
}

int main() {
    FASTIO
    cout << solve();
}
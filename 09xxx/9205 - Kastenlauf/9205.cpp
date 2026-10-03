#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

string solution() {
    int n;
    cin >> n;
    vector<pair<int, int>> node;
    for(int i = 0; i < n+2; i++) {
        int a, b; cin >> a >> b;
        node.push_back({a, b});
    }

    vector<vector<int>> graph(n+2);
    for(int i = 0; i < n+2; i++) {
        for(int j = i+1; j < n+2; j++) {
            if(dist(node[i], node[j]) > 1000) continue;
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }

    queue<int> bfs;
    vector<bool> visited(n+2, false);
    bfs.push(0);
    visited[0] = true;
    while(!bfs.empty()) {
        int now = bfs.front(); bfs.pop();
        for(int next : graph[now]) {
            if(next == n+1) return "happy";
            else if(visited[next]) continue;
            bfs.push(next);
            visited[next] = true;
        }
    }
    return "sad";
}

int main() {
    FASTIO
    int tc; cin >> tc;
    while(tc--) cout << solution() << "\n";
}
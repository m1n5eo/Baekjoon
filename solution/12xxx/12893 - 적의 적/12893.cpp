#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 2222

int solve() {
    int n, m, a, b, temp;
    cin >> n >> m;
    vector<int> parent(n+2, 0);
    vector<vector<int>> graph(n+2, vector<int>(0));
    for(int i = 0; i <= n+1; i++) parent[i] = i;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a+1].push_back(b+1);
        graph[b+1].push_back(a+1);
        temp = a+1;
    }

    queue<int> q;
    q.push(temp);
    parent[temp] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int g : graph[now]) {
            if(parent[g] == 1-parent[now]) continue;
            else if(parent[g] == parent[now]) return 0;
            else {
                q.push(g);
                parent[g] = 1-parent[now];
            }
        }
    }
    return 1;
}

int main() {
    FASTIO
    cout << solve();
}
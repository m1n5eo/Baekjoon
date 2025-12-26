#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n, m;
vector<vector<int>> graph(MAX);
vector<int> value(MAX, 0), result(MAX, 0);

void traversal(int node, int now) {
    result[node] = now;
    for(int i : graph[node]) {
        traversal(i, now+value[i]);
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        if(temp == -1) continue;
        graph[temp].push_back(i);
    }
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        value[a] += b;
    }
    traversal(1, 0);
}

int main() {
    FASTIO
    solve();
    for(int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
}
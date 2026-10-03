#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 222

int n, m;
vector<int> a(MAX, -1), b(MAX, -1);
vector<vector<int>> graph(MAX);
vector<bool> visited;

bool dfs(int x) {
    visited[x] = true;
    for(int y : graph[x]) {
        if(b[y] == -1 || (!visited[b[y]] && dfs(b[y]))) {
            a[x] = y;
            b[y] = x;
            return true;
        }
    }
    return false;
}

int solution() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if(a%2 == b%2) continue;
        else if(a%2) graph[a-1].push_back(b-1);
        else graph[b-1].push_back(a-1);
    }

    int ret = 0;
    for(int i = 0; i < n; i+=2) {
        if(a[i] == -1) {
            visited = vector<bool>(MAX, false);
            if(dfs(i)) ret += 1;
        }
    }
    if(n-ret*2 > 0) return ret*2+1;
    else return ret*2;
}

int main() {
    FASTIO
    cout << solution();
}
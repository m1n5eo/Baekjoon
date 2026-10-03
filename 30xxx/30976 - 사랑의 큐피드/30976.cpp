#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 888

vector<vector<int>> graph(MAX);
vector<int> a(MAX, -1), b(MAX, -1);
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> woman(n), man(m);
    for(int i = 0; i < n; i++) cin >> woman[i].first;
    for(int i = 0; i < m; i++) cin >> man[i].first;
    for(int i = 0; i < n; i++) cin >> woman[i].second;
    for(int i = 0; i < m; i++) cin >> man[i].second;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(man[j].first < woman[i].second && woman[i].first > man[j].second) {
                graph[i].push_back(n+j);
                graph[n+j].push_back(i);
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == -1) {
            visited = vector<bool>(MAX, false);
            if(dfs(i)) ret += 1;
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solution();
}
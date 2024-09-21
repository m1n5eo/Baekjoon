#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

#define MAX 111111

int n, m, r, result[MAX];
bool visit[MAX];
vector<int> node[MAX];

bool compare(int a, int b) {
    return a > b;
}

void dfs(int x, int cnt) {
    if(visit[x] == true) return;

    visit[x] = true;
    result[x] = cnt;

    int node_size = node[x].size();

    for(int i = 0; i < node_size; i++) {
        dfs(node[x][i], cnt+1);
    }

    return;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    memset(result, -1, sizeof(int)*MAX);

    cin >> n >> m >> r;

    for(int _ = 0; _ < m; _++) {
        int a, b;
        cin >> a >> b;

        node[a].push_back(b);
        node[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        sort(node[i].begin(), node[i].end(), compare);
    }

    dfs(r, 0);

    for(int i = 1; i <= n; i++) {
        cout << result[i] << "\n";
    }
}
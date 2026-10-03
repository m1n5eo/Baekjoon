#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int up = 0, down = 0;
vector<vector<vector<int>>> graph(2, vector<vector<int>>(MAX, vector<int>(0)));
vector<vector<bool>> check(2, vector<bool>(MAX, false));

void dfs(int x, int idx) {
    check[idx][x] = true;

    for(auto graphs : graph[idx][x]) {
        if(check[idx][graphs] == false) {
            dfs(graphs, idx);

            if(idx == 0) down += 1;
            else up += 1;
        }
    }
}

int main() {
    FASTIO

    int n, m, x, a, b;

    cin >> n >> m >> x;
    
    for(int _ = 0; _ < m; _++) {
        cin >> a >> b;

        graph[0][a].push_back(b);
        graph[1][b].push_back(a);
    }

    dfs(x, 0);
    dfs(x, 1);

    cout << up+1 << " " << n-down;
}
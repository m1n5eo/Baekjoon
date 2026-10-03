#include <iostream>
#include <vector>
using namespace std;

int n, res[100001];
bool visited[100001];
vector<int> node[100001];

void dfs(int idx) {
    visited[idx] = true;

    int len = node[idx].size();
    
    for(int i = 0; i < len; i++) {
        int temp = node[idx][i];

        if(visited[node[idx][i]] == false) {
            res[node[idx][i]] = idx;
            dfs(node[idx][i]);
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int x, y;

        cin >> x >> y;

        node[x].push_back(y);
        node[y].push_back(x);
    }

    dfs(1);

    for(int i = 2; i <= n; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}
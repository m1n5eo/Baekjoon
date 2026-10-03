#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define MAX 111111

int n, m, a, b, k;
vector<vector<int>> graph(MAX, vector<int>(0));
vector<int> parent(MAX, 0), depth(MAX, 0), result;
vector<bool> visit(MAX, false);
vector<vector<int>> sparseTable((int)(log(MAX)/log(2))+1, vector<int>(MAX, 0));

void dfs(int x, int dep) {
    visit[x] = true;
    k = max(k, (int)(log(dep)/log(2)));

    for(int g : graph[x]) {
        if(visit[g] == false) {
            parent[g] = x;
            depth[g] = dep+1;

            dfs(g, dep+1);
        }
    }
}

int main() {
    FASTIO

    cin >> n;

    for(int _ = 0; _ < n-1; _++) {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    for(int i = 0; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            sparseTable[i][j] = i != 0? sparseTable[i-1][sparseTable[i-1][j]] : parent[j];
        }
    }

    cin >> m;

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b;

        if(depth[a] != depth[b]) {
            if(depth[a] < depth[b]) {
                swap(a, b);
            }

            int diff = depth[a] - depth[b];

            for(int i = 0; diff > 0; i++) {
                if(diff%2 == 1) {
                    a = sparseTable[i][a];
                }

                diff /= 2;
            }
        }

        if(a != b) {
            for(int i = k; i >= 0; i--) {
                if(sparseTable[i][a] != 0 && sparseTable[i][a] != sparseTable[i][b]) {
                    a = sparseTable[i][a];
                    b = sparseTable[i][b];
                }
            }

            a = sparseTable[0][a];
        }
        
        result.push_back(a);
    }

    for(int r : result) {
        cout << r << " ";
    }
}
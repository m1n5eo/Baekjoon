#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000
#define MAX 111

int main() {
    FASTIO

    int n, m, a, b, result = INF, idx;
    vector<vector<int>> graph(MAX, vector<int>(MAX, INF));

    cin >> n >> m;

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b;

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        int sum = 0;

        for(int j = 1; j <= n; j++) {
            if(graph[i][j] != INF) {
                sum += graph[i][j];
            }
        }

        sum -= graph[i][i];

        if(result > sum) {
            result = sum;
            idx = i;
        }
    }

    cout << idx;
}
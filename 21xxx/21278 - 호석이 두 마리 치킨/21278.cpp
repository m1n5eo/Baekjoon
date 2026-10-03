#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000
#define MAX 111

int main() {
    FASTIO

    int n, m, a, b;
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
                if(!(i == j || j == k || k == i)) {
                    if(graph[i][k] != INF && graph[k][j] != INF) {
                        graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    int p, q, distance = INF;

    for(int x = 1; x <= n; x++) {
        for(int y = x+1; y <= n; y++) {
            int dist = 0;

            for(int i = 1; i <= n; i++) {
                dist += min(graph[x][i], graph[y][i]);
            }

            if(distance > dist) {
                distance = dist;
                p = x;
                q = y;
            }
        }
    }

    cout << p << " " << q << " " << distance*2;
}
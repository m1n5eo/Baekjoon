#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111
#define INF 1e9

int n, m, r;
int item[MAX], graph[MAX][MAX];

int main() {
    FASTIO

    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> item[i];
    }

    for(int i = 0; i < r; i++) {
        int a, b, d;
        cin >> a >> b >> d;

        graph[a][b] = d;
        graph[b][a] = d;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i != j && graph[i][k] != INF && graph[k][j] != INF) {
                    if(graph[i][j] == INF) graph[i][j] = graph[i][k]+graph[k][j];
                    else graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
                }
            }
        }
    }

    int result = 0;
    
    for(int i = 1; i <= n; i++) {
        int sum = 0;

        for(int j = 1; j <= n; j++) {
            if(i == j || graph[i][j] <= m) {
                sum += item[j];
            }
        }

        result = max(result, sum);
    }

    cout << result;
}
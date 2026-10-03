#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11
#define INF 1e9

int n, m, result = INF, dist[MAX][MAX];
bool visit[MAX];

void backtracking(int idx, int sum, int cnt) {
    if(cnt == n-1) {
        result = min(result, sum);
        return;
    }

    visit[idx] = true;

    for(int i = 0; i < n; i++) {
        if(visit[i] == false) {
            backtracking(i, sum+dist[idx][i], cnt+1);
        }
    }

    visit[idx] = false;
}

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][k] != 0 && dist[k][j] != 0) {
                    if(dist[i][j] == 0) dist[i][j] = dist[i][k]+dist[k][j];
                    else dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    backtracking(m, 0, 0);

    cout << result;
}
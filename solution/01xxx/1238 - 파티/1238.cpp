#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111
#define INF 1e9

int n, m, x, dist[MAX][2], arr[MAX][MAX][2];
bool visit[MAX][2];

int main() {
    FASTIO

    cin >> n >> m >> x;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            arr[i][j][0] = INF;
            arr[i][j][1] = INF;
        }

        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    for(int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;

        arr[a][b][0] = d;
        arr[b][a][1] = d;

        if(a == x) dist[b][0] = arr[a][b][0];
        if(b == x) dist[a][1] = arr[b][a][1];
    }

    visit[x][0] = true;
    visit[x][1] = true;

    for(int k = 0; k < 2; k++) {
        for(int _ = 0; _ < n-2; _++) {
            int next, temp = INF;

            for(int i = 1; i <= n; i++) {
                if(visit[i][k] == false && temp > dist[i][k]) {
                    temp = dist[i][k];
                    next = i;
                }
            }

            visit[next][k] = true;

            for(int i = 1; i <= n; i++) {
                if(i != x && dist[i][k] > dist[next][k]+arr[next][i][k]) {
                    dist[i][k] = dist[next][k]+arr[next][i][k];
                }
            }
        }
    }

    int result = 0;
    
    for(int i = 1; i <= n; i++) {
        if(i != x) result = max(result, dist[i][0]+dist[i][1]);
    }

    cout << result;
}
#include <bits/stdc++.h>
using namespace std;

int n, m, k, a, b;
int arr[101][101], food[10001];

void dfs(int i, int j, int k) {
    if(i <= 0 || i > n || j <= 0 || j > m) return;
    else if(arr[i][j] != 1) return;

    arr[i][j] = k;

    dfs(i-1, j, k);
    dfs(i+1, j, k);
    dfs(i, j-1, k);
    dfs(i, j+1, k);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
    }

    int cnt = 2;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(arr[i][j] == 1) {
                dfs(i, j, cnt);
                cnt++;
            }
        }
    }

    int maxi = -1234567890, maxx = -1234567890;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(arr[i][j] != 0) {
                food[arr[i][j]]++;
                maxi = max(maxi, arr[i][j]);
            }
        }
    }

    for(int i = 2; i <= maxi; i++) maxx = max(maxx, food[i]);

    if(maxx == -1234567890) printf("0");
    else printf("%d", maxx);
}

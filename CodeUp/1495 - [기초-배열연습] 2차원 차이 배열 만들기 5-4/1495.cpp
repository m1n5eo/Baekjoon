#include <bits/stdc++.h>
using namespace std;

int d[1001][1001], sum[1001][1001];

int main() {
    int n, m, k;
    int x1, y1, x2, y2, u;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &u);
        d[x1][y1] = d[x1][y1]+u;
        d[x2+1][y2+1] = d[x2+1][y2+1]+u;
        d[x1][y2+1] = d[x1][y2+1]-u;
        d[x2+1][y1] = d[x2+1][y1]-u;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) sum[i][j] = d[i][j];
            else if(j == 0) sum[i][0] = d[i][0] + sum[i-1][0];
            else if(i == 0) sum[0][j] = d[0][j] + sum[0][j-1];
            else sum[i][j] = d[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}
#include <bits/stdc++.h>
using namespace std;

int arr1[103][103], arr2[103][103];

int main() {
    int n, m, a, b, cnt;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        arr1[a][b] = 1;
        arr2[b][a] = 1;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j || j == k || k == i) continue;
                if(arr1[i][k] && arr1[k][j]) arr1[i][j] = 1;
                if(arr2[i][k] && arr2[k][j]) arr2[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(arr1[i][j] == 0 && arr2[i][j] == 0) cnt = cnt + 1;
        }
        printf("%d\n", cnt);
    }
}
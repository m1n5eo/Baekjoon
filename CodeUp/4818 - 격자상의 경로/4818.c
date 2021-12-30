#include <stdio.h>

int arr[22][22];

int main() {
    int n, m, k, s1, s2, dap = 1;
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = 1;
        }
    }

    if(k % m == 0) s1 = k / m - 1;
    else s1 = k / m;
    s2 = k - ((k / m)*m) - 1;
    if(s2 == -1) s2 = m - 1;

    for(int i = 1; i <= s1; i++) {
        for(int j = 1; j <= s2; j++) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    dap = dap * arr[s1][s2];
    for(int i = s1+1; i < n; i++) {
        for(int j = s2+1; j < m; j++) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    printf("%d", dap * arr[n-1][m-1]);
}
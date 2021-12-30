#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, y, arr[101][101], maxx = -1234567890;
    scanf("%d %d %d %d", &m, &n, &x, &y);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i <= n-y; i++) {
        for(int j = 0; j <= m-x; j++) {
            int sum = 0;
            for(int ii = i; ii < i+y; ii++) {
                for(int jj = j; jj < j+x; jj++) {
                    sum = sum + arr[ii][jj];
                }
            }
            //printf("%d ", sum);
            maxx = max(maxx, sum);
        }
    }
    //printf("\n");
    printf("%d", maxx);
}
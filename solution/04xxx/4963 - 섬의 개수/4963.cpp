#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, k;
int arr[55][55];

void dfs(int x, int y) {
    if(x < 0 || x > n-1 || y < 0 || y > m-1) return;
    if(!(arr[x][y] == 1)) return;
    //printf("%d %d \ ", x, y);
    arr[x][y] = k;
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);
    dfs(x-1, y-1);
    dfs(x-1, y+1);
    dfs(x+1, y-1);
    dfs(x+1, y+1);
}

int main() {
    scanf("%d %d", &m, &n);
    while(n != 0 && m != 0) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        k = 2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == 1) {
                    dfs(i, j);
                    k++;
                }
            }
        }
        printf("%d\n", k-2);
        /*for(int i = 0; i < n; i++) {
            for(int j = 0; j< m;j++) {
                printf("%d", arr[i][j]);
            }
            printf("\n");
        }*/
        scanf("%d %d", &m, &n);
    }
}

#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
int arr[301][301], imsi[301][301];

void dfs(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    if(imsi[x][y] == 0) return;

    imsi[x][y] = 0;

    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);
}

void chk_cgh() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] <= 0) imsi[i][j] = 0;
            else imsi[i][j] = 1;
        }
    }
}

int bd(int x, int y) {
    int c = 0;
    if(arr[x-1][y] == 0) c++;
    if(arr[x+1][y] == 0) c++;
    if(arr[x][y-1] == 0) c++;
    if(arr[x][y+1] == 0) c++;
    //printf("arr[%d][%d] = %d\n", x, y, c);
    return c;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    while(1) {
        cnt++;
        int k = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] <= 0) continue;
                k = bd(i,j);
                arr[i][j] = arr[i][j]-k;
                if(arr[i][j] <= 0) arr[i][j] = -1;
            }
        }
        int bingha = 0;
        chk_cgh();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(imsi[i][j] == 1) {
                    bingha++;
                    dfs(i,j);
                }
            }
        }
        if(bingha > 1) {
            printf("%d", cnt);
            break;
        }
        else {
            int dn = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(arr[i][j] == -1) arr[i][j] = 0;
                    if(arr[i][j] == 0) dn++;
                }
            }
            if(dn == n*m) {
                printf("0");
                break;
            }
        }
    }
}
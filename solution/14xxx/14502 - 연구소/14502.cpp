#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m, k = 0, maxx = -1234567890;
int xx[66], yy[66], arr[11][11], imsi[11][11], imsi2[11][11];
int dx[4] = {-1, 1, 0, 0},
    dy[4] = {0, 0, -1, 1};
queue <pair<int,int>> q;

void print() {
    printf("\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d", imsi2[i][j]);
        }
        printf("\n");
    }
}

void bfs() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            imsi2[i][j] = arr[i][j];
        }
    }

    for(int i = 0; i < k; i++) q.push({xx[i], yy[i]});

    while(!q.empty()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();
        for(int k = 0; k < 4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(arr[nx][ny] == 0) {
                    arr[nx][ny] = 2;
                    q.push({nx, ny});

                }
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) cnt++;
        }
    }
    maxx = max(maxx, cnt);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = imsi2[i][j];
        }
    }
}

void wall(int cnt) {
    if(cnt == 3) {
        bfs();
        return;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                arr[i][j] = 1;
                wall(cnt+1);
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
            imsi[i][j] = arr[i][j];
            if(arr[i][j] == 2) {
                xx[k] = i;
                yy[k] = j;
                k++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                for(int a = 0; a < n; a++) {
                    for(int b = 0; b < m; b++) {
                        arr[i][j] = imsi[i][j];
                    }
                }
                arr[i][j] = 1;
                wall(1);
                arr[i][j] = 0;
            }
        }
    }

    printf("%d", maxx);
}

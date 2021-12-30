#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int cnt[123], arr[111][111]; // 0은 영역없음 / 1은 영역있음

void dfs(int x, int y, int count) {
    if(x < 0 || y < 0 || x >= n || y >= m) return;
    else if(arr[x][y]) return;
    arr[x][y] = count;
    dfs(x-1, y, count);
    dfs(x+1, y, count);
    dfs(x, y-1, count);
    dfs(x, y+1, count);
}

int main() {
    int x1, y1, x2, y2, count = 2;
    scanf("%d %d %d", &m, &n, &k);
    for(int t = 0; t < k; t++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int i = x1; i < x2; i++) {
            for(int j = y1; j < y2; j++) {
                arr[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!arr[i][j]) {
                dfs(i, j, count);
                count++;
            }
        }
    }

    count = count-2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] != 1) {
                cnt[arr[i][j]-2]++;
            }
        }
    }

    sort(cnt, cnt+count);
    printf("%d\n", count);
    for(int i = 0; i < count; i++) printf("%d ", cnt[i]);
}

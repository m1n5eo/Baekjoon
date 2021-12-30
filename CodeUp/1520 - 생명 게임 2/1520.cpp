#include <bits/stdc++.h>
using namespace std;

int arr[177][177], cnt[177][177];

int main() {
    int n, m, k, birth, live, death;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &birth, &live, &death);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d", &k);

    while(k--) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cnt[i][j] = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] + arr[i][j-1] + arr[i][j+1] + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1];
                if(!arr[i][j]) cnt[i][j] = cnt[i][j]==birth? 1:0;
                else cnt[i][j] = live<=cnt[i][j] && cnt[i][j]<death? 1:0;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                arr[i][j] = cnt[i][j];
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
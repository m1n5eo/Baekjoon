#include <bits/stdc++.h>
using namespace std;

int stu[503][503], cnt[503];

int main() {
    int n, m, a, b, c = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        stu[a][b] = 1;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i==j || j==k || k==i) continue;
                if(stu[i][k] && stu[k][j]) {
                    stu[i][j] = 1;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(stu[i][j] && i != j) {
                cnt[i]++;
                cnt[j]++;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(cnt[i] == n-1) c++;
    }
    printf("%d", c);
}
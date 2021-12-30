#include <bits/stdc++.h>
using namespace std;

int virus[103][103];

int main() {
    int n, m, computer1, computer2;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &computer1, &computer2);
        virus[computer1][computer2] = 1;
        virus[computer2][computer1] = 1;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(virus[i][k] == 1 && virus[k][j] == 1) {
                    virus[i][j] = 1;
                    virus[j][i] = 1;
                }
            }
        }
    }

    int cnt = -1;
    for(int i = 1; i <= n; i++) {
        if(virus[i][1] == 1) cnt = cnt + 1;
    }
    printf("%d", cnt);
}

#include <bits/stdc++.h>
using namespace std;

int fri[103][103];

int main() {
    int n, m, a, b, idx, sum = 0, minn = 1000000003;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        fri[a][b] = 1;
        fri[b][a] = 1;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(fri[i][k] && fri[k][j]) {
                    if(fri[i][j] == 0) fri[i][j] = fri[i][k] + fri[k][j];
                    else if(fri[i][j] > fri[i][k] + fri[k][j]) fri[i][j] = fri[i][k] + fri[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sum = sum + fri[i][j];
        }
        sum = sum - fri[i][i];
        if(minn > sum) {
            minn = sum;
            idx = i;
        }
        sum = 0;
    }
    printf("%d", idx);
}

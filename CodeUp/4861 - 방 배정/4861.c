#include <stdio.h>

int main() {
    int n, k, s, y, cnt = 0;
    scanf("%d %d", &n, &k);
    int baejung[2][7];
    for(int i = 0; i <= 1; i++) {
        for(int j = 1; j <= 6; j++) {
            baejung[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &s, &y);
        baejung[s][y] = baejung[s][y] + 1;
    }
    for(int i = 0; i <= 1; i++) {
        for(int j = 1; j <= 6; j++) {
            if(baejung[i][j] % k == 0) {
                cnt = cnt + baejung[i][j]/k;
            }
            else if(baejung[i][j] % k != 0) {
                cnt = cnt + baejung[i][j]/k+1;
            }
        }
    }
    printf("%d", cnt);
}
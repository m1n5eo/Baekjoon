#include <stdio.h>

void f(int n) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            for(int k = j; k <= n; k++) {
                if(i+j+k == n && i+j > k) {
                    printf("%d %d %d\n", i, j, k);
                    cnt = cnt + 1;
                }
            }
        }
    }

    if(cnt == 0) printf("-1");
}

int main() {
    int n;
    scanf("%d", &n);
    f(n);
}
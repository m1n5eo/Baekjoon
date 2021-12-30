#include <stdio.h>

int main() {
    int n, sum = 0, cnt;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        cnt = 0;
        for(int j = 2; j < i; j++) {
            if(i != j && i % j == 0) {
                cnt = cnt + 1;
            }
        }
        if(cnt == 0) sum = sum + i;
    }
    printf("%d", sum);
}
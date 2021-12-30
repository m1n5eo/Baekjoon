#include <stdio.h>

int main() {
    int n, score, sum = 0, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &score);
        if(score == 1) {
            cnt = cnt + 1;
            sum = sum + cnt;
        }
        else if(score == 0) {
            cnt = 0;
        }
    }
    printf("%d", sum);
}
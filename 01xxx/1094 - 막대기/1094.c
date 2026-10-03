#include <stdio.h>

int main() {
    int n, res;

    scanf("%d", &n);

    int stick = 64, cnt = 0;

    for(int stick = 64; stick >= 0; stick/=2) {
        if(n >= stick) {
            n -= stick;
            cnt += 1;
        }
        if(n == 0) break;
    }

    printf("%d", cnt);

    return 0;
}
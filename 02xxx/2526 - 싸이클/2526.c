#include <stdio.h>

int main() {
    int n, p, k = 1, cnt[111] = {0};
    scanf("%d %d", &n, &p);
    int temp = n;
    while(1) {
        temp = (n*temp)%p;
        if(!cnt[temp]) cnt[temp] = k++;
        else {
            printf("%d", k-cnt[temp]);
            break;
        }
    }
}
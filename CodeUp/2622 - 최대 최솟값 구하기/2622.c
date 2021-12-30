#include <stdio.h>

int main() {
    int n, minnum = 1, maxnum = 1, min = 100000, max = -1;
    scanf("%d", &n);
    int br[n+1];
    for(int i = 1; i <= n; i++) {
        scanf("%d", &br[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(br[i] > max) {
            max = br[i];
            maxnum = i;
        }
        if(br[i] < min) {
            min = br[i];
            minnum = i;
        }
    }
    printf("%d : %d\n", maxnum, max);
    printf("%d : %d", minnum, min);
}
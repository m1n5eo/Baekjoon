#include <stdio.h>
int cbg[101];
int main() {
    int n, sum = 0, max = -1, maxid = -1;
    for(int i = 1; i <= 10; i++) {
        scanf("%d", &n);
        sum = sum + n;
        cbg[n/10] = cbg[n/10] + 1;
    }
    printf("%d\n", sum/10);
    for(int i = 1; i <= 100; i++) {
        if(max < cbg[i]) {
            max = cbg[i];
            maxid = i;
        }
    }

    printf("%d", maxid*10);
}
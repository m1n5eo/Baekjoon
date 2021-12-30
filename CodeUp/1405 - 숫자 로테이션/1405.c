#include <stdio.h>

int main() {
    int n, t, m;
    scanf("%d", &n);
    m = n;
    int k[n+1];
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
    }
    while(m--) {
    for(int i = 1; i <= n; i++) {
        printf("%d ", k[i]);
    }
        printf("\n");
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            t = k[i];
        }
        else if (i == n) {
            k[i-1] = k[i];
            k[i] = t;
        }
        else {
            k[i-1] = k[i];
        }
    }
    }
}
#include <stdio.h>

int main() {
    int n[6], min = 10000009, max = -1000009;
    for(int i = 1; i <= 5; i++) scanf("%d", &n[i]);
    for(int i = 1; i <= 5; i++) {
        if(max < n[i]) max = n[i];
        if(min > n[i]) min = n[i];
    }
    printf("%d\n%d", max, min);
}
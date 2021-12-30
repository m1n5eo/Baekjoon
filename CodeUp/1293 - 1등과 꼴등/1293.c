#include <stdio.h>

int main() {
    int n, max = 0, min = 111;
    scanf("%d", &n);
    int score[n+1];
    for(int i = 1; i <= n; i++) scanf("%d", &score[i]);
    for(int i = 1; i <= n; i++) {
        if(max < score[i]) max = score[i];
        else if (min > score[i]) min = score[i];
    }
    printf("%d %d", max, min);
}
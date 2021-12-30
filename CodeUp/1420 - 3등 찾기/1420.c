#include <stdio.h>

int main() {
    int n, score[50], rank[50];
    char name[50][20];

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s %d", name[i], &score[i]);
        rank[i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(score[i] < score[j]) {
                rank[i]++;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(rank[i] == 3) {
            printf("%s", name[i]);
        }
    }
}
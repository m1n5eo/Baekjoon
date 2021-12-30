#include <stdio.h>

int main() {
    int n, check;
    scanf("%d", &n);
    int comp[n+1];
    for(int i = 1; i <= n; i++) scanf("%d", &comp[i]);

    for(int i = 1; i <= n; i++) {
        printf("%d: ", i);
        for(int j = 1; j <= n; j++) {
            if(i != j && comp[i] < comp[j]) printf("< ");
            else if(i != j && comp[i] == comp[j]) printf("= ");
            else if(i != j && comp[i] > comp[j]) printf("> ");
        }
        printf("\n");
    }
}
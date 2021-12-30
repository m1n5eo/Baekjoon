#include <stdio.h>

int main() {
    int n, m, temp;
    scanf("%d %d", &n, &m);
    int comp[n+m+1];
    for(int i = 1; i <= n+m; i++) scanf("%d", &comp[i]);

    for(int i = 1; i <= n+m; i++) {
        for(int j = 1; j <= i; j++) {
            if(comp[i] < comp[j]) {
                temp = comp[i];
                comp[i] = comp[j];
                comp[j] = temp;
            }
        }
    }

    for(int i = 1; i <= n+m; i++) printf("%d ", comp[i]);
}
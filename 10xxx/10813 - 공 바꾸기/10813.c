#include <stdio.h>

int n, m, box[111];
int a, b;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        box[i] = i;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        int temp = box[a];
        box[a] = box[b];
        box[b] = temp;
    }
    for(int i = 1; i <= n; i++) {
        printf("%d ", box[i]);
    }
}
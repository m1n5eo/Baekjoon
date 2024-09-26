#include <stdio.h>

#define MAX 2222

int max(int x, int y) {
    if(x < y) return y;
    else return x;
}

int main() {
    int n, m, temp, result = 0, clap[MAX] = {0, };

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &temp);
            clap[j] += temp;
        }
    }

    scanf("%d", &n);

    for(int i = 0; i < m-n+1; i++) {
        int sum = 0;

        for(int j = i; j < i+n; j++) {
            sum += clap[j];
        }

        result = max(result, sum);
    }

    printf("%d", result);
}
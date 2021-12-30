#include <stdio.h>

int arr[43], fibo[43];

int main() {
    int n, m, a, cnt = 0, sum = 1;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &a);
        arr[a] = 1;
    }
    fibo[0] = fibo[1] = 1;

    for(int i = 2; i <= n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    for(int i = 1; i <= n; i++) {
        if(arr[i] == 1) {
            sum = sum * fibo[cnt];
            cnt = 0;
        }
        else cnt++;
    }
        if(cnt != 0) {
            sum = sum * fibo[cnt];
        }

    printf("%d", sum);
}
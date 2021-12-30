#include <stdio.h>

int _1, _2, _11, _22, arr[100000003];

void check(int num) {
    _1 = num / 10;
    _2 = num % 10;
}

int main() {
    int n, m, k, sum = 0;
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < 10; i++) {
        if(i == k) arr[i] = arr[i] + 1;
    }
    for(int i = 10; i <= 100000000; i++) {
        check(i);
        arr[i] = arr[_1] + arr[_2];
    }

    for(int i = n; i <= m; i++) sum = sum + arr[i];

    printf("%d", sum);
}
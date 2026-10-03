#include <stdio.h>

int arr[11111];

int main() {
    for(int i = 1; i*i <= 10000; i++) {
        arr[i*i] = 1;
    }

    int n, m, sum = 0, min_num = -1;
    scanf("%d %d", &n, &m);
    for(int i = m; i >= n; i--) {
        if(arr[i] == 1) {
            min_num = i;
            sum += i;
        }
    }

    if(min_num == -1) {
        printf("-1");
    }
    else {
        printf("%d\n%d", sum, min_num);
    }

    return 0;
}
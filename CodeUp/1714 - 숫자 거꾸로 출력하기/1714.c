#include <stdio.h>

int arr[3333];

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    if(n == 0) {
        printf("0");
        return 0;
    }
    while(n > 0) {
        arr[cnt] = n % 10;
        n = n / 10;
        cnt = cnt + 1;
    }
    for(int i = 0; i < cnt; i++) {
        printf("%d", arr[i]);
    }
}
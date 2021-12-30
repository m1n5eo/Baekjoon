#include <stdio.h>

int n, sum = 0;

void func(int cnt) {
    sum = sum + cnt;
    if(cnt == n) return;
    func(cnt + 1);
}

int main() {
    int cnt = 1;
    scanf("%d", &n);
    func(cnt);
    printf("%d", sum);
}
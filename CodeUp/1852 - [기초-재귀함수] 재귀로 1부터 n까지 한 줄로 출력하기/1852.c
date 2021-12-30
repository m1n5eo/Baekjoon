#include <stdio.h>

int n;

void func(int cnt) {
    printf("%d ", cnt);
    if(cnt == n) return;
    func(cnt + 1);
}

int main() {
    int cnt = 1;
    scanf("%d", &n);
    func(cnt);
}
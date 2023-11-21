#include <stdio.h>

int main() {
    int n, ans = 2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) ans += ans-1;
    printf("%d", ans*ans);
}

#include <stdio.h>

int main() {
    int n, m, u;
    scanf("%d %d %d", &n, &m, &u);
    if(m >= n && u >= n) printf("%d", n);
    else if(n >= m && u >= m) printf("%d", m);
    else if(n >= u && m >= u) printf("%d", u);
}
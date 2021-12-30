#include <stdio.h>

int print(int s, int e) {
    if(s == e+1) return 0;
    else if(s % 2 == 1) printf("%d ", s);
    return print(s+1, e);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    print(a, b);
}
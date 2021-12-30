#include <stdio.h>

int main() {
    int n, m, first, middle, finish;
    scanf("%d", &n);
    first = 1;
    if(n % 2 == 0) middle = n / 2;
    else if(n % 2 != 0) middle = n / 2 +1;
    finish = n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        if(first == i) printf("%d ", m);
        if(middle == i) printf("%d ", m);
        if(finish == i) printf("%d ", m);
    }
}
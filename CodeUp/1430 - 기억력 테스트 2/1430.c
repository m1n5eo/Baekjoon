#include <stdio.h>

int n, m, num, _num[10000001], que;

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &num), _num[num] = 1;
    }
    scanf("%d", &m);
    while(m--) {
        scanf("%d", &que);
        if(_num[que]) {
            printf("1 ");
        }
        else printf("0 ");
    }
}
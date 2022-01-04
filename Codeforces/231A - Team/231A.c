#include <stdio.h>

int main() {
    int n, cnt = 0, petya, vasya, tonya;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &petya, &vasya, &tonya);
        if(petya && vasya) cnt++;
        else if(vasya && tonya) cnt++;
        else if(petya && tonya) cnt++;
    }
    printf("%d", cnt);
}
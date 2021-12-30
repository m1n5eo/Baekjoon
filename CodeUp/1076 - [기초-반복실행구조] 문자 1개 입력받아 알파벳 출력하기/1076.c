#include <stdio.h>

int main() {
    char n;
    scanf(" %c", &n);
    for(int i = 'a'; i <= n; i++) {
        printf("%c ", i);
    }
}
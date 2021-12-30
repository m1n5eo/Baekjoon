#include <stdio.h>

int main() {
    int n[11], sum = 0;
    for(int i = 1; i <= 10; i++) {
        scanf("%1d", &n[i]);
        sum = sum + n[i];
    }
    if(sum % 7 == 4) printf("suspect");
    else printf("citizen");
}
#include <stdio.h>

int main() {
    int n, f;
    scanf("%d %d", &n, &f);
    for(int i = 0; i < 100; i++) {
        n = (n/100)*100+i;
        if(n%f == 0) {
            printf("%02d", i);
            return 0;
        }
    }
}
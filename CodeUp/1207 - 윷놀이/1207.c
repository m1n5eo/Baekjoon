#include <stdio.h>

int main() {
    int n, i, c = 0;
    for(int i = 1; i <= 4; i++) {
        scanf ("%d", &n);
        if(n == 1) c++;
    }
    if(c == 1) printf("도");
    else if(c == 2) printf("개");
    else if(c == 3) printf("걸");
    else if(c == 4) printf("윷");
    else printf("모");
}
#include <stdio.h>

int main() {
    int t, res = 40;

    for(int i = 0; i < 10; i++) {
        scanf("%d", &t);
        if(t == 1) res += 1;
        else if(t == 2) res += 2;
        else if(t == 3) res -= 1;
    }

    if(res%4 == 0) printf("N");
    else if(res%4 == 1) printf("E");
    else if(res%4 == 2) printf("S");
    else if(res%4 == 3) printf("W");
}
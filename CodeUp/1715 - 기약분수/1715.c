#include <stdio.h>

int main() {
    int up, down, min;
    scanf("%d %d", &up, &down);
    if(up > down) min = down;
    else min = up;
    for(int i = min; i >= 2; i--) {
        if(up % i == 0 && down % i == 0) {
            up = up / i;
            down = down / i;
            break;
        }
    }
    printf("%d %d", up, down);
}
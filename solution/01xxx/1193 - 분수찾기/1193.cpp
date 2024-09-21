#include <stdio.h>

int main() {
    int n, x = 1, y = 1, sw = 1, k = 1;
    scanf("%d", &n);
    while(1) {
        if(k == n) break;
        if(x == 1 || y == 1) {
            sw = 1-sw;
            if(sw == 0) {y++;k++;}
            else if(sw == 1) {x++;k++;}
        }
        if(k == n) break;
        if(sw == 0) {x++;y--;k++;}
        else if(sw == 1) {x--;y++;k++;}
    }
    printf("%d/%d", x, y);
}

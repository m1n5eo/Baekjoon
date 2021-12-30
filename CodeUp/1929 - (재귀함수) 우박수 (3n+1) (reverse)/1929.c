#include <stdio.h>

int f(int num) {
    if(num == 1) {
        printf("1\n");
        return 0;
    }
    if(num % 2 == 1) {
        f(num*3+1);
        printf("%d\n", num);
    }
    else if (num % 2 == 0) {
        f(num/2);
        printf("%d\n", num);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    f(n);
}
#include <stdio.h>

int n;
char ch[7];

int f(int num) {
    if(num == n){
        printf("%s\n", ch);
        return 0;
    }

    ch[num]='O';
    f(num+1);
    ch[num]='X';
    f(num+1);
}

int main() {
    scanf("%d", &n);
    f(0);
}
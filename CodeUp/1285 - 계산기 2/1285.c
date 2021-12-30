#include <stdio.h>

int main() {
    int n, sum = 0;
    char ch = '!';
    scanf("%d", &n);
    sum = n;
    while(ch != '=') {
        scanf("%c", &ch);
        if(ch == '=') break;
        scanf("%d", &n);
        if(ch == '+') sum = sum + n;
        else if (ch == '-') sum = sum - n;
        else if (ch == '*') sum = sum * n;
        else if (ch == '/') sum = sum / n;
    }
    printf("%d", sum);
}
#include <stdio.h>
#include <string.h>

void check(int n) {
    int i = 0, cnt = 0;
    char ch[6] = {0, 0, 0, 0, 0, 0};
    while(n > 0) {
        ch[i] = (n % 10)+48;
        n = n / 10;
        i = i + 1;
    }
    int len = strlen(ch);
    for(int i = 0; i < len/2; i++) {
        if(ch[i] == ch[len-i-1]) cnt = cnt + 1;
    }

    if(cnt == len/2) printf("YES");
    else printf("NO");
}

int rvs(int n) {
    int sum = 0;
    while(n > 0) {
        sum = sum * 10;
        sum = sum + n %10;
        n = n / 10;
    }
    return sum;
}

int main() {
    int num;
    scanf("%d", &num);
    int su = num + rvs(num);
    check(su);
}
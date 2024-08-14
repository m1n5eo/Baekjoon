#include <stdio.h>
#include <string.h>

#define MAX 1111

int n, cnt;

int recursion(const char *s, int l, int r) {
    cnt += 1;

    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s) {
    return recursion(s, 0, strlen(s)-1);
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char str[MAX];
        cnt = 0;

        scanf("%s", str);

        printf("%d ", isPalindrome(str));
        printf("%d\n", cnt);
    }
}
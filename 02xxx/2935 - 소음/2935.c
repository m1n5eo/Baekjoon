#include <stdio.h>
#include <string.h>

int main() {
    char a[111], b[111], sign;

    scanf("%s", a);
    scanf(" %c", &sign);
    scanf("%s", b);

    int len_a = strlen(a), len_b = strlen(b);

    if(sign == '+') {
        if(len_a > len_b) {
            for(int i = 0; i < len_a; i++) {
                if(i == 0 || i == len_a-len_b) printf("1");
                else printf("0");
            }
        }
        else if(len_a == len_b) {
            for(int i = 0; i < len_a; i++) {
                if(i == 0) printf("2");
                else printf("0");
            }
        }
        else if(len_a < len_b) {
            for(int i = 0; i < len_b; i++) {
                if(i == 0 || i == len_b-len_a) printf("1");
                else printf("0");
            }
        }
    }
    else if(sign == '*') {
        for(int i = 0; i < len_a+len_b-1; i++) {
            if(i == 0) printf("1");
            else printf("0");
        }
    }

    return 0;
}
#include <stdio.h>

int main() {
    int cnt = 0;
    char ch[10];
    gets(ch);
    for(int i = 0; i < 10; i++) {
        if(ch[i] == 't') {
            printf("%d ", i+1);
        }
    }
}
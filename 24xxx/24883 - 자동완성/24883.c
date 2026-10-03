#include <stdio.h>

int main() {
    char ch;

    scanf("%c", &ch);
    printf(ch == 'N' || ch == 'n'? "Naver D2" : "Naver Whale");
}
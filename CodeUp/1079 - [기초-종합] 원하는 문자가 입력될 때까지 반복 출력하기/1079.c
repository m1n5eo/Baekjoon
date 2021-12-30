#include <stdio.h>

int main() {
    char ch;
    while(1) {
        scanf(" %c", &ch);
        if(ch != 'q') {
            printf("%c\n", ch);
        }
        else {
            printf("%c\n", ch);
            break;
        }
    }
}
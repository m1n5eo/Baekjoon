#include <stdio.h>

int main() {
    char ch[5] = {NULL, NULL, NULL, NULL, NULL};
    gets(ch);
    if (ch[0] == 'l' && ch[1] == 'o' && ch[2] == 'v' && ch[3] == 'e' && ch[4] != NULL) {
        return 0;
    }
    else if(ch[0] == 'l' && ch[1] == 'o' && ch[2] == 'v' && ch[3] == 'e') {
        printf("I love you.");
    }
}
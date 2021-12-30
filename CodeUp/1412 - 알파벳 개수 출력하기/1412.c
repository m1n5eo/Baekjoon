#include <stdio.h>

int main() {
    char line[90];
    int alpha[26] = {0, }, i = 0, k;
    
    gets(line);
    
    while(line[i] != 0) {
        if(line[i] >= 97 && line[i] <= 122) {
            alpha[line[i]-97]++;
        }
        i++;
    }

    for(k = 0; k < 26; k++) {
        printf("%c:%d\n", k+97, alpha[k]);
    }
}
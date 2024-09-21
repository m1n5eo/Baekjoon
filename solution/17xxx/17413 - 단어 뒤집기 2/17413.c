#include <stdio.h>
#include <string.h>

int main() {
    char str[111111];

    scanf("%[^\n]s", str);

    int len = strlen(str);
    int start = 0, end, sw = 0;

    for(int i = 0; i <= len; i++) {
        if(sw == 1) {
            if(i == len || str[i] == '>') {
                end = i;

                for(int j = start; j <= end; j++) {
                    printf("%c", str[j]);
                }

                start = i+1;
                sw = 0;
            }
        }
        else if(sw == 0) {
            if(i == len || str[i] == ' ' || str[i] == '<') {
                end = i-1;

                for(int j = end; j >= start; j--) {
                    printf("%c", str[j]);
                }
                if(str[i] == '<') printf("<");
                else printf(" ");

                start = i+1;
                if(str[i] == '<') sw = 1;
            }
        }
    }
}
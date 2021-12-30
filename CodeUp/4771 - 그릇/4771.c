#include <stdio.h>
#include <string.h>

int main() {
    char bowl[53];
    gets(bowl);
    int len = strlen(bowl), sum = 0;
    for(int i = 0; i < len; i++) {
        if(i == 0) sum = sum + 10;
        else if(bowl[i] == bowl[i-1]) sum = sum + 5;
        else if(bowl[i] != bowl[i-1]) sum = sum + 10;
    }
    printf("%d", sum);
}
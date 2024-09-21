#include <stdio.h>

int main() {
    int sum = 10;
    char bowl[55];
    scanf("%s", bowl);
    int len = strlen(bowl);
    for(int i = 1; i < len; i++) {
        if(bowl[i] == bowl[i-1]) sum += 5;
        else sum += 10;
    }
    printf("%d", sum);
}
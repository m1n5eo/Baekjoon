#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char str[1111], ignore;

    scanf("%d", &n);
    
    for(int t = 0; t < n; t++) {
        scanf("%c", &ignore);
        scanf("%[^\n]s", str);

        int start = 0, end = 0, len = strlen(str);

        for(int i = 0; i <= len; i++) {
            if(i == len || str[i] == ' ') {
                end = i-1;

                for(int j = end; j >= start; j--) {
                    printf("%c", str[j]);
                }
                printf(" ");

                start = i+1;
            }
        }
        printf("\n");
    }

    return 0;
}
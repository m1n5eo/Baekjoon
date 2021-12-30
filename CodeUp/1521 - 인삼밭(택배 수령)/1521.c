#include <stdio.h>

int main() {
    int n, day, insam, cnt = 0;
    scanf("%d %d", &n, &day);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &insam);
            if(insam != -1 && 0 <= insam+day && insam+day <= 5) cnt = cnt + 1;
        }
    }
    printf("%d", cnt);
}
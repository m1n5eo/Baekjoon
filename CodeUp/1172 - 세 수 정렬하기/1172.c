#include <stdio.h>

int main() {
    int num[4], t;
    for(int i = 1; i <= 3; i++) scanf("%d", &num[i]);
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            if(num[i] < num[j]) {
                t = num[i];
                num[i] = num[j];
                num[j] = t;
            }
        }
    }
    for(int i = 1; i <= 3; i++) printf("%d ", num[i]);
    return 0;
}
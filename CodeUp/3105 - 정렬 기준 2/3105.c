#include <stdio.h>

int count[50002], save[50002];

int main() {
    int n, num, max = 50000;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        count[num]++;
    }

    for(int i = 1; i <= 50000; i++) save[i] = count[i];

    while(1) {
        max = 50000;
        for(int i = 50000; i >= 1; i--) {
            if(count[max] < count[i]) {
                max = i;
            }
            else if(count[max] == count[i]) {
                if(max < i) {
                    max = i;
                }
            }
        }
        if(count[max] == 0) break;
        for(int i = 1; i <= save[max]; i++) {
            printf("%d ", max);
            count[max] = 0;
        }
    }
}
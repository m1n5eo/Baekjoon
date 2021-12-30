#include <stdio.h>

void cal(int stone[5][5]) {
    int max = -1, sum = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = i; k <= i+2; k++) {
                for(int l = j; l <= j+2; l++) {
                    sum = sum + stone[k][l];
                }
            }
            if(max < sum) max = sum;
            sum = 0;
        }
    }
    printf("%d", max);
}

int main() {
    int st[5][5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            scanf("%d", &st[i][j]);
        }
    }

    cal(st);
}
#include <stdio.h>

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

int main() {
    int n, res = 0, dice[3];

    scanf("%d", &n);

    for(int t = 0; t < n; t++) {
        scanf("%d %d %d", &dice[0], &dice[1], &dice[2]);

        for(int i = 0; i < 3; i++) {
            for(int j = i+1; j < 3; j++) {
                if(dice[i] > dice[j]) {
                    int temp = dice[i];
                    dice[i] = dice[j];
                    dice[j] = temp;
                }
            }
        }

        if(dice[0] == dice[1] && dice[1] == dice[2]) {
            res = max(res, 10000+dice[0]*1000);
        }
        else if(dice[0] == dice[1]) {
            res = max(res, 1000+dice[0]*100);
        }
        else if(dice[1] == dice[2]) {
            res = max(res, 1000+dice[1]*100);
        }
        else {
            res = max(res, dice[2]*100);
        }
    }

    printf("%d", res);

    return 0;
}
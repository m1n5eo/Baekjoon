#include <stdio.h>

int main() {
    int cm[11], sum = 0;

    for(int i = 0; i < 9; i++) {
        scanf("%d", &cm[i]);
        sum += cm[i];
    }

    for(int i = 0; i < 9; i++) {
        for(int j = i+1; j < 9; j++) {
            sum -= (cm[i]+cm[j]);
            if(sum == 100) {
                for(int k = 0; k < 9; k++) {
                    if(k != i && k != j) {
                        printf("%d\n", cm[k]);
                    }
                }
                return 0;
            }
            sum += (cm[i]+cm[j]);
        }
    }
}
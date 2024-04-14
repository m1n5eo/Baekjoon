32.86#include <stdio.h>

int main() {
    int num, correct[111], score = 0;

    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d", &correct[i]);

        if(correct[i] == 0 || i == 0) {
            continue;
        }
        else if(correct[i] != 0 && correct[i-1] == 0) {
            continue;
        }
        else if(correct[i] != 0 && correct[i-1] != 0) {
            correct[i] = correct[i-1] + 1;
        }
    }

    for(int i = 0; i < num; i++) {
        score += correct[i];
    }
    printf("%d", score);
    
    return 0;
}
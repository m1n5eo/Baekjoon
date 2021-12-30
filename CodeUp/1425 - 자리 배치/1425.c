#include <stdio.h>

int main() {
    int student, jr, cnt = 1, t;
    scanf("%d %d", &student, &jr);
    int cm[student+1];
    for(int i = 1; i <= student; i++) {
        scanf("%d", &cm[i]);
    }

    for(int i = 1; i <= student; i++) {
        for(int j = i; j <= student; j++) {
            if(cm[i] > cm[j]) {
                t = cm[i];
                cm[i] = cm[j];
                cm[j] = t;
            }
        }
    }

    for(int i = 1; i <= student/jr+1; i++) {
        for(int j = 1; j <= jr && cnt != student+1; j++) {
            printf("%d ", cm[cnt]);
            cnt = cnt + 1;
        }
        printf("\n");
    }
}
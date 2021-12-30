#include <stdio.h>

int main() {
    int n, max = -1, min = 1004;
    scanf("%d", &n);
    int student[n+1];
    for(int i = 0; i < n; i++) {
        scanf("%d", &student[i]);
        if(max < student[i]) {
            max = student[i];
        }
        if(min > student[i]) {
            min = student[i];
        }
    }
    printf("%d", max-min);
}
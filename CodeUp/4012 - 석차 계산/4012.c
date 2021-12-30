#include <stdio.h>

struct data {
    int score, rank;
}arr[201];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i].score);
        arr[i].rank = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i].score > arr[j].score) {
                arr[j].rank = arr[j].rank + 1;
            }
            else if(arr[i].score < arr[j].score) {
                arr[i].rank = arr[i].rank + 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].score, arr[i].rank);
    }
}
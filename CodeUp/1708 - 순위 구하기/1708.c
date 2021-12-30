#include <stdio.h>

struct data {
    int score, equal;
}arr[1001];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i].score);
        arr[i].equal = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i].score < arr[j].score) {
                arr[i].equal = arr[i].equal + 1;
            }
            else if(arr[i].score > arr[j].score) {
                arr[j].equal = arr[j].equal + 1;
            }
        }
    }

    for(int i = 0; i < n; i++) printf("%d %d\n", arr[i].score, arr[i].equal);
}
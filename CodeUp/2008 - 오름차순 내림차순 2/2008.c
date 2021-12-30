#include <stdio.h>

int main() { //             오름차순은 1이고 내림차순은 0이다
    int n, check;
    scanf("%d", &n);
    int arr[n+1];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n-1; i++) {
        if(arr[i] < arr[i+1]) {
            check = 1;
            break;
        }
        else if (arr[i] > arr[i+1]) {
            check = 0;
            break;
        }
        else if (arr[i] == arr[i+1] && i == n-2) {
            printf("섞임");
            return 0;
        }
    }

    for(int i = 0; i < n-1 && check == 1; i++) {
        if(arr[i] > arr[i+1]) {
            break;
        }
        else if (i == n-2) {
            printf("오름차순");
            return 0;
        }
    }

    for(int i = n-1; i > 0; i--) {
        if(arr[i] > arr[i-1]) {
            break;
        }
        else if (i == 1) {
            printf("내림차순");
            return 0;
        }
    }
    printf("섞임");
    return 0;
}
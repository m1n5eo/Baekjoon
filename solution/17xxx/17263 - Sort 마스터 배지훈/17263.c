#include <stdio.h>

int max_function(int a, int b) {
    if(a > b) return a;
    else return b;
}

int main() {
    int num, arr, arr_max = 0;

    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d", &arr);
        arr_max = max_function(arr, arr_max);
    }

    printf("%d", arr_max);
}
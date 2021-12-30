#include <stdio.h>

int main() {
    int size[5], temp;
    for(int i = 0; i < 5; i++) {
        scanf("%d", &size[i]);
        for(int j = 0; j < i; j++) {
            if(size[i] < size[j]) {
                temp = size[i];
                size[i] = size[j];
                size[j] = temp;
            }
        }
    }
    printf("%d", size[2]);
}
#include <stdio.h>

int main() {
    int n, su[102];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &su[i]);
    }

    for(int i = 0; i < n; i+=2) {
        if(su[i] < su[i+1]) printf("%d ", su[i]);
        else if(su[i] >= su[i+1]) printf("%d ", su[i+1]);
    }
}
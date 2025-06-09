#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;

void cantor(int left, int right) {
    if(left >= right) return;
    else if(left+1 == right) {
        printf("-");
        return;
    }

    int mid1 = left + (right - left) / 3;
    int mid2 = mid1 + (right - left) / 3;

    cantor(left, mid1);
    for(int _ = mid1; _ < mid2; _++) printf(" ");
    cantor(mid2, right);
}

int main() {
    while(scanf("%d", &n) != EOF) {
        cantor(0, pow(3, n));
        printf("\n");
    }
}
#include <stdio.h>

int n;

void star(int start, int end) {
    if(end+1 == start) return;
    else printf("*");
    return star(start+1, end);
}

void triangle(int num) {
    if(num == 0) return;
    star(1, num);
    printf("\n");
    return triangle(num-1);
}

int main() {
    scanf("%d", &n);
    triangle(n);
}
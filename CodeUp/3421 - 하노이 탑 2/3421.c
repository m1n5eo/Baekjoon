#include <stdio.h>

int cnt = 0;

void hanoi(int n, int src, int dest, int temp) {
	cnt = cnt + 1;
	if(n == 1) return;

	hanoi(n - 1, src, temp, dest);
	hanoi(n - 1, temp, dest, src);
}

int main() {
	int n;
    scanf("%d", &n);
    hanoi(n, 1, 3, 2);
    printf("%d", cnt);
}
#include <stdio.h>

int main() {
	int n, sum = 0;
	scanf("%d", &n);
	int number[n+1];
	for(int i = 1; i <= n; i++) {
		scanf("%d", &number[i]);
		if(number[i] % 5 == 0) sum = sum + number[i];
	}
	printf("%d", sum);
}
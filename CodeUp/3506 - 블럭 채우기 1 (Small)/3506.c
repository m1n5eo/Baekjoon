#include <stdio.h>

int arr[10003] = {0, 1,};

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n+1; i++) {
		arr[i] = arr[i-1] + arr[i-2];
	}
	printf("%d", arr[n+1]);
}
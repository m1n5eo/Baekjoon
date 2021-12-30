#include <stdio.h>

int arr[22];

int main() {
	int n;
	scanf("%d", &n);
	arr[0] = 1;
	arr[1] = 2;
	for(int i = 2; i <= n; i++) {
		arr[i] = arr[i-1] + arr[i-2];
	}
	printf("%d", arr[n]);
}
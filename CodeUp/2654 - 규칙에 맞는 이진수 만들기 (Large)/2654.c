#include <stdio.h>

int arr[100003];

int main() {
	int n;
	scanf("%d", &n);
	arr[0] = 1;
	arr[1] = 2;
	for(int i = 2; i <= n; i++) {
		arr[i] = arr[i-1] % 1000000007 + arr[i-2] % 1000000007;
	}
	printf("%d", arr[n] % 1000000007);
}
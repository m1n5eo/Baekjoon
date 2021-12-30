#include <stdio.h>

int arr[22];

int main() {
	int k, n;
	scanf("%d %d", &k, &n);
	for(int i = 1; i <= k; i++) scanf("%d", &arr[i]);
	for(int i = k+1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			arr[i] = arr[i] + arr[i-j];
		}
	}
	
	printf("%d", arr[n]);
}
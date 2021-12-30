#include <stdio.h>

int arr[100000003];

int main() {
	int n, m;
	long long int cnt = 0;
	scanf("%d %d", &n, &m);
	arr[0] = arr[1] = arr[2] = arr[4] = arr[5] = arr[7] = arr[8] = 0;
	arr[3] = arr[6] = arr[9] = 1;
	for(int i = 10; i <= m; i++) {
		arr[i] = arr[i%10] + arr[i/10];
	}
	for(int i = n; i <= m; i++) {
		cnt = cnt + arr[i];
	}
	printf("%lld", cnt);
}
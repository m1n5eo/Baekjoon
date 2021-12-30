#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[100003]; 

int main() {
	int n, k;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	scanf("%d", &k);
	
	for(int i = 1; i <= n; i++) {
		if(arr[i] == k) {
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
}
#include <stdio.h>
#include <algorithm>

using namespace std;

int k[10003];

int main() {
	int n, m, sum = 0, a = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &k[i]);
		a = a + k[i];
	}
	scanf("%d", &m);
	if(a <= m) {
		sort(k, k+n);
		printf("%d", k[n-1]);
		return 0;
	}
	int left = 0, right = m, mid = (left+right)/2;
	
	while(left+1 < right) {
		// printf("%d %d %d ", left, mid, right);
		for(int i = 0; i < n; i++) {
			if(mid < k[i]) sum = sum + mid;
			else sum = sum + k[i];
		}
		if(sum <= m) {
			left = mid;
			mid = (left+right)/2;
		}
		else if(sum > m) {
			right = mid;
			mid = (left+right)/2;
		}
		// printf("%d\n", sum);
		sum = 0;
	}
	printf("%d", mid);
}
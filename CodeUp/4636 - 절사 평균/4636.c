#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	double sum = 0, arr[100003];
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%lf", &arr[i]);
	sort(arr, arr+n);
	
	for(int i = k; i < n-k; i++) sum = sum + arr[i];
	printf("%.2lf\n", sum / (n-k*2));
	sum = 0;
	
	for(int i = 0; i < k; i++) sum = sum + arr[k];
	for(int i = n-k; i < n; i++) sum = sum + arr[n-k-1];
	for(int i = k; i < n-k; i++) sum = sum + arr[i];
	printf("%.2lf\n", sum / n);
}
#include <stdio.h>

int main() {
	int n, arr[10002], up = 0, down = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if(i != 0 && arr[i-1] > arr[i]) up++;
		else if(i != 0 && arr[i-1] < arr[i]) down++;
	}
	
	printf("%d %d", down, up);
}
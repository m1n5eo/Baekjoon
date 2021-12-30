#include <stdio.h>

int main() {
	int n, cnt = 1, max = -1, su[100003];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &su[i]);
	
	if(n == 1) {
		printf("1");
		return 0;
	}
	
	for(int i = 0; i < n-1; i++) {
		if(su[i] <= su[i+1]) cnt =  cnt + 1;
		else cnt = 1;
		if(max < cnt) max = cnt;
	}
	for(int i = 0; i < n-1; i++) {
		if(su[i] >= su[i+1]) cnt = cnt + 1;
		else cnt = 1;
		if(max < cnt) max = cnt;
	}
	printf("%d", max);
}
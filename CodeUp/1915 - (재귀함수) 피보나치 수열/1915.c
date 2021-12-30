#include <stdio.h>

int pibo(int a) {
	if(a==1) return 1;
	else if (a==2) return 1;
	return pibo(a-1) + pibo(a-2);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", pibo(n));
	return 0;
}
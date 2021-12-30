#include <stdio.h>

int check(int num) {
	if(num == 1) return 1;
	else if(num % 2 == 0) return check(num/2) + 1;
	else return check(num*3+1) + 1;
} 

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	printf("%d", check(n));
}
#include <stdio.h>

int cnt = 0;

void function(int num, int save) {
	if(num == 0) {
		if(cnt <= 0) printf("%d", save);
		printf("\n");
		return;
	}
	else if(num % 10 == 3 || num % 10 == 6 || num % 10 == 9) {
		printf("K");
		cnt = cnt + 1;
	}
	function(num/10, save);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = n; i <= m; i++) {
		function(i, i);
		cnt = 0;
	}
}
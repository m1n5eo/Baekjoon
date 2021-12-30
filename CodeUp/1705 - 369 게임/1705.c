#include <stdio.h>

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	int check = n;
	while(check != 0) {
		if(check % 10 == 3 || check % 10 == 6 || check % 10 == 9) {
			printf("K");
			cnt = cnt + 1;
		}
		check = check / 10;
	}
	if (cnt == 0) printf("%d", n);
}
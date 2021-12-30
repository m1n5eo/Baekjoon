#include <stdio.h>

int main() {
	int num[9], n = 0, bg = -1;
	for(int i = 0; i < 9; i++) {
		scanf("%d", &num[i]);
		if(bg < num[i]) {
			bg = num[i];
			n = i;
		}
	}
	printf("%d\n%d", bg, n+1);
}
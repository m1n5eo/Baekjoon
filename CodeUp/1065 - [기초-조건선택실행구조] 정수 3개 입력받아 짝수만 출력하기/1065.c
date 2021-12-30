#include <stdio.h>

int main() {
	int a[3];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	for(int i = 0; i < 3; i++) {
		if(a[i] % 2== 0) printf("%d\n", a[i]);
	}
}
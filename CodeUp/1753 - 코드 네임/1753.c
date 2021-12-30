#include <stdio.h>
#include <string.h>

int main() {
	int n, len;
	char name[101];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", name);
		len = strlen(name);
		for(int j = len-1; j >= 0; j--) {
			printf("%c", name[j]);
		}
		printf("\n");
	}
}
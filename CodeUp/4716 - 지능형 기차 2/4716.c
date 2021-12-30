#include <stdio.h>

int main() {
	int in[10], out[10], sum = 0, bg = -1;
	for(int i = 0; i < 10; i++) {
		scanf("%d %d", &out[i], &in[i]);
		sum = sum + in[i] - out[i];
		if(bg < sum) bg = sum;
	}
	printf("%d", bg);
}
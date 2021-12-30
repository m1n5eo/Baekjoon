#include <stdio.h>

int main() {
	int person[10], down = 0, up = 0;
	double sum = 0;
	for(int i = 0; i < 10; i++) {
		scanf("%d", &person[i]);
		sum = sum + person[i];
	}
	sum = sum / 10;
	printf("%.1lf\n", sum);
	for(int i = 0; i < 10; i++) {
		if(sum > person[i]) down = down + 1;
		else if(sum <= person[i]) up = up + 1;
	}
	printf("%d %d", up, down);
}
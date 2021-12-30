#include <stdio.h>

int main() {
	int time, score;
	scanf("%d %d", &time, &score);
	while(time < 90) {
		score++;
		time = time + 5;
	}
	printf("%d", score);
}
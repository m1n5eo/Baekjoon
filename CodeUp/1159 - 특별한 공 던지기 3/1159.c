#include <stdio.h>

int main() {
	int score;
	scanf("%d", &score);
	if(50 <= score && score <= 70) printf("win");
	else if(score % 6 == 0) printf("win");
	else printf("lose");
}
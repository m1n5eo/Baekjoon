#include <stdio.h>

int main() {
	int score;
	scanf("%d", &score);
	if(60 <= score && score <= 70) printf("win");
	else if(30 <= score && score <= 40) printf("win");
	else printf("lose");
}
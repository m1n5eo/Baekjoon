#include <stdio.h>

int main() {
	double score;
	scanf("%lf", &score);
	if(50 <= score && score <= 60) printf("win");
	else printf("lose");
}
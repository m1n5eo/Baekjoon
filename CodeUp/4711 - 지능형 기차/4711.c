#include <stdio.h>

int main() {
	int n, m, people = 0, max = -1;
	for(int i = 0; i < 4; i++) {
		scanf("%d %d", &n, &m);
		people = people + m - n;
		if(max < people) max = people;
	}
	printf("%d", max);
}	
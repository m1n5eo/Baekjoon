#include <stdio.h>

int main() {
	int year, month, day, gender, nouse;
	scanf("%2d %2d %2d %1d %d", &year, &month, &day, &gender, &nouse);
	if(gender == 1 || gender == 2) {
		printf("%d ", 2012 - (1900 + year) + 1);
		if(gender == 1) printf("M");
		else if(gender == 2) printf("F");
	}
	else if(gender == 3 || gender == 4) {
		printf("%d ", 2012 - (2000 + year) + 1);
		if(gender == 3) printf("M");
		else if(gender == 4) printf("F");
	}
}
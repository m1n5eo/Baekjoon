#include <stdio.h>

int main() {
	int n, m, sum = 0;
	scanf("%d %d", &n, &m);
	if (n == 1) sum = sum + 400;
	else if (n == 2) sum = sum + 340;
	else if (n == 3) sum = sum + 170; 
	else if (n == 4) sum = sum + 100;
	else if (n == 5) sum = sum + 70;
	
	if (m == 1) sum = sum + 400;
	else if (m == 2) sum = sum + 340;
	else if (m == 3) sum = sum + 170;
	else if (m == 4) sum = sum + 100;
	else if (m == 5) sum = sum + 70;
	
	if(sum <= 500) printf("no angry");
	else if (sum > 500) printf("angry");
}
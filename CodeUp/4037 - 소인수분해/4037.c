#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n, k = 2;
	scanf("%d", &n);
	
	while(1) {
		if(n <= 1) break;
		if (n % k == 0){
			printf("%d ", k);
			n = n / k;
		}
		else k++;
	}
}
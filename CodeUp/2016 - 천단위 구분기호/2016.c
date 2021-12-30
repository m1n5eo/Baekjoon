#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int jari[n+1];
	for(int i = 1; i <= n; i++) scanf("%1d", &jari[i]);
	if(n <= 3) {
		for(int i = 1; i <= n; i++) {
			printf("%d", jari[i]);
		}
	}
	else if(n % 3 == 0) {
		for(int i = 1; i <= n; i++) {
			if(i != 1 && i % 3 == 1) printf(",");
			printf("%d", jari[i]);
		}
	}
	else if(n % 3 == 1) {
		for(int i = 1; i <= n; i++) {
			if(i % 3 == 2) printf(",");
			printf("%d", jari[i]);
		}
	}
	else if(n % 3 == 2) {
		for(int i = 1; i <= n; i++) {
			if(i % 3 == 0) printf(",");
			printf("%d", jari[i]);
		}
	}
}
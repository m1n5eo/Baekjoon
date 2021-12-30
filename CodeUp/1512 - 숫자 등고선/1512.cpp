#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, y;
	scanf("%d", &n);
	scanf("%d %d", &x, &y);
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			printf("%d ", abs(x-i)+abs(y-j)+1);
		}
		printf("\n");
	}
}
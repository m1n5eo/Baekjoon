#include <bits/stdc++.h>
using namespace std; 

int main() {
	for(int i = 0; i <= 9; i++) {
		for(int j = 0; j <= 9; j++) {
			for(int k = 0; k <= 9; k++) {
				if(i != j && j != k && k != i) {
					if((i*100+j*10+k)-(i*10+j) == k*11) {
						printf("%d%d%d-%d%d=%d%d", i, j, k, i, j, k, k);
						return 0;
					}
				}
			}
		}
	}
}
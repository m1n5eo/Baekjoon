#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int sum = 0, wrong[10];
	for(int i = 0; i < 9; i++) {
		scanf("%d", &wrong[i]);
	}
	sort(wrong, wrong+9);
	
	for(int i = 0; i < 9; i++) {
		for(int j = i+1; j < 9; j++) {
			for(int k = 0; k < 9; k++) {
				if(!(k == i || k == j)) {
					sum = sum + wrong[k];
				}
			}
			if(sum == 100) {
				for(int k = 0; k < 9; k++) {
					if(!(k == i || k == j)) {
						printf("%d\n", wrong[k]);
					}
				}
			}
			sum = 0;
		}
	}
}
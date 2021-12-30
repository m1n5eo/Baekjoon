#include <stdio.h>

int main() {
	int n, temp;
	scanf("%d", &n);
	int br[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &br[i]);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			if(br[i] < br[j]) {
				temp = br[i];
				br[i] = br[j];
				br[j] = temp;
			}
		}
		printf("%d ", br[i]);
	}
}
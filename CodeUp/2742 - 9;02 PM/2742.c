#include <stdio.h>

int main() {
	int n, t;
	scanf("%d", &n);
	int br[n+1];
	for(int i = 1; i <= n; i++) {
		scanf("%d", &br[i]);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i+1; j <= n; j++) {
			if(br[i] < br[j]) {
				t = br[i];
				br[i] = br[j];
				br[j] = t;
			}
		}
	}
	t = br[1];
	br[1] = br[1+n/2];
	br[1+n/2] = t;
	for(int i = 1; i <= n; i++) {
		printf("%d ", br[i]);
	}
}
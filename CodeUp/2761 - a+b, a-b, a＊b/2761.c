#include <stdio.h>

int main() {
	int n, m, br[3], temp;
	scanf("%d %d", &n, &m);
	br[0] = n+m;
	br[1] = n-m;
	br[2] = n*m;
	for(int i = 0; i < 3; i++) {
		for(int j = i; j < 3; j++) {
			if(br[i] < br[j]) {
				temp = br[i];
				br[i] = br[j];
				br[j] = temp;
			}
		}
	}
	printf("%d", br[1]);
}
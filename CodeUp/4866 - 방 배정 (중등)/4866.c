#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k, s, y, _12, _34w, _34m, _56w, _56m;

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &s, &y);
		if(y == 1 || y == 2) _12 = _12 + 1;
		else if(s == 0) {
			if(y == 3 || y == 4) _34w = _34w + 1;
			else if(y == 5 || y == 6) _56w = _56w + 1;
		}
		else {
			if(y == 3 || y == 4) _34m = _34m + 1;
			else if(y == 5 || y == 6) _56m = _56m + 1;
		}
	}
	
	printf("%d", (_12+k-1)/k + (_34w+k-1)/k + (_34m+k-1)/k + (_56w+k-1)/k + (_56m+k-1)/k);
}
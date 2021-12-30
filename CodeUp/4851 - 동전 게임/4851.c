#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int round, casee, n, m, nam, cha;
	scanf("%d %d", &round, &casee);
	for(int i = 0; i < casee; i++) {
		scanf("%d %d", &n, &m);
		if(n == m) {
			printf("1\n");
			continue;
		}
		else if(n > m) {
			nam = round-n;
			cha = n-m;
		}
		else if(n < m) {
			nam = round-m;
			cha = m-n;
		}
		
		if(n > m && cha - nam <= 2) printf("1\n");
		else if(n < m && cha - nam <= 1) printf("1\n");
		else printf("0\n");
	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sum = 0;
	for(int i = 0; i < 10; i++) {
		scanf("%1d", &n);
		sum = sum + n;
	}
	
	if(sum % 7 == 4) printf("Bad");
	else printf("Good");
}
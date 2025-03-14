#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int f(int left, int right, int kim, int lim, int k) {
	if(left <= kim && lim <= right) return min(f(left, left + (right-left+1)/2 - 1, kim, lim, k-1), f(left + (right-left+1)/2, right, kim, lim, k-1));
	else return k;
}

int main() {
	FASTIO

	int n, kim, lim;

	cin >> n >> kim >> lim;

	int k = 0;
	n -= 1;

	while(n) {
		n /= 2;
		k += 1;
	}

	n = 1;
	
	for(int i = 0; i < k; i++) {
		n *= 2;
	}
	
	cout << f(1, n, min(kim, lim), max(kim, lim), k) + 1;
}
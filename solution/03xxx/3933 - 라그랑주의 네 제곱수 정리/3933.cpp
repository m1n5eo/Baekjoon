#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 33333

int n;
vector<int> square;
vector<bool> check(MAX, false);

void init() {
	for(int i = 0; i*i < MAX; i++) {
		square.push_back(i*i);
		check[i*i] = true;
	}
}

int solve() {
	int ret = 0, ss = square.size();
	for(int i = 0; i < ss; i++) {
		for(int j = i; j < ss; j++) {
			for(int k = j; k < ss; k++) {
				int last = n - square[i] - square[j] - square[k];
				if(square[i] > last || square[j] > last || square[k] > last) break;
				else if(check[last] == true) ret += 1;
			}
		}
	}
	return ret;
}

int main() {
	FASTIO
	init();
	while(cin >> n) {
		if(n == 0) break;
		else cout << solve() << "\n";
	}
}
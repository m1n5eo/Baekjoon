#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int main() {
	FASTIO
	
	int n;
	vector<lli> sequence = {0, 1, 1, 1};

	cin >> n;
	for(int i = 4; i <= n; i++) {
		sequence.push_back(sequence[i-1] + sequence[i-3]);
	}

	cout << sequence.back();
}
#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55

int main() {
	FASTIO

	int n, temp, x = 1, result = 0;
	vector<int> count(MAX, 0);

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> temp;
		count[temp] += 1;
	}

	for(int i = 1; i <= 50; i++) {
		if(count[i] == 0) break;

		result += x * count[i];
		x *= count[i];
	}

	cout << result;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 555555

int main() {
	// FASTIO

	int n, temp;
	vector<int> sequence(MAX, 0), distance(MAX, 0), index(MAX, 0);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> temp;

		sequence[i] = temp;
		index[temp] = i;
	}

	for(int i = 1; i <= n; i++) {
		if(sequence[i] != i) {
			int idx = index[i];
			int add = index[i] - i;

			distance[i] += add;
			distance[sequence[i]] += add;

			index[sequence[i]] = index[i];
			index[i] = i;

			int temp = sequence[i];
			sequence[i] = sequence[idx];
			sequence[idx] = temp;
		}
	}

	for(int i = 1; i <= n; i++) {
		cout << distance[i] << " ";
	}
}
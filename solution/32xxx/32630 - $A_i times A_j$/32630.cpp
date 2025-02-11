#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

bool compare(lli a, lli b) {
	return a < b;
}

int main() {
	FASTIO
	
	int n;
	lli temp, sum = 0;
	vector<lli> vec;

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> temp;

		vec.push_back(temp);
		sum += temp;
	}

	lli result = sum;

	sort(vec.begin(), vec.end(), compare);

	result = max(result, sum + (vec[n-1] * vec[n-2] * 2) - (vec[n-1] + vec[n-2]));
	result = max(result, sum + (vec[0] * vec[1] * 2) - (vec[0] + vec[1]));

	cout << result;
}
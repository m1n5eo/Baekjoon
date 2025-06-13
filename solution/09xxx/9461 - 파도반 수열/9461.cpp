#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int main() {
	FASTIO

	int t, n;
	vector<lli> triangle = {0, 1, 1, 1, 2};
	
	for(int i = 5; i <= 100; i++) {
		triangle.push_back(triangle[i-1] + triangle[i-5]);
	}

	cin >> t;
	for(int _ = 0; _ < t; _++) {
		cin >> n;
		cout << triangle[n] << " ";
	}
}
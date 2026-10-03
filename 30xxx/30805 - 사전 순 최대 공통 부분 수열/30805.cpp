#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111

int a, b, aidx, bidx;
vector<int> v1(MAX, 0), v2(MAX, 0), result;

int main() {
	FASTIO

	cin >> a;
	for(int i = 0; i < a; i++) cin >> v1[i];
	cin >> b;
	for(int i = 0; i < b; i++) cin >> v2[i];

	while(aidx < a && bidx < b) {
		pair<int, int> idx = {aidx, bidx};
		int k = 0;
		for(int i = aidx; i < a; i++) {
			for(int j = bidx; j < b; j++) {
				if(v1[i] == v2[j] && v1[i] > k) {
					k = v1[i];
					idx.first = i;
					idx.second = j;
				}
			}
		}
		if(k == 0) break;
		result.push_back(k);
		aidx = idx.first + 1;
		bidx = idx.second + 1;
	}

	cout << result.size() << "\n";
	for(int r : result) cout << r << " ";
}
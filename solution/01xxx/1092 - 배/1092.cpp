#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

bool reversed(int a, int b) {
	return a > b;
}

int solve() {
    int n, m, temp;
	vector<int> crane, box;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		crane.push_back(temp);
	}
    cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> temp;
		box.push_back(temp);
	}

    sort(crane.begin(), crane.end(), reversed);
    sort(box.begin(), box.end(), reversed);

	if(crane[0] < box[0]) return -1;

	int ret = 0;
	while(!box.empty()) {
		ret += 1;
		for(int i = 0; i < crane.size(); i++) {
			for(int j = 0; j < box.size(); j++) {
				if(crane[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
	}
	return ret;
}

int main() {
	FASTIO
	cout << solve();
}
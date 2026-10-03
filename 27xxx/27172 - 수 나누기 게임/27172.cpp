#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1111111

int n, m, temp;
vector<int> card;

vector<int> solve() {
	vector<int> ret(n, 0), count(INF, -1);
	for(int i = 0; i < n; i++) count[card[i]] = i;
	for(int i = 0; i < n; i++) {
		int k = card[i];
		for(int j = k*2; j <= m; j+=k) {
			if(count[j] != -1) {
				ret[count[k]] += 1;
				ret[count[j]] -= 1;
			}
		}
	}
	return ret;
}

int main() {
	FASTIO

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		card.push_back(temp);
		m = max(m, temp);
	}
	for(int sol : solve()) cout << sol << " ";
}
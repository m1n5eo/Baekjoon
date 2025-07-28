#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, m, q, d, t;
string temp, x, y, z, name;
vector<pair<string, int>> algo;
map<string, int> member;

bool compare(pair<string, int> a, pair<string, int> b) {
	if(abs(member[name]-a.second) != abs(member[name]-b.second)) return abs(member[name]-a.second) < abs(member[name]-b.second);
	else return a.first < b.first;
}

int main() {
	FASTIO

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp >> d;
		algo.push_back({temp, d});
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> temp >> t;
		member[temp] = t;
	}
	cin >> q;
	for(int _ = 0; _ < q; _++) {
		cin >> x >> y >> z;
		if(z == "chan!") {
			name = x;
			cout << "hai!" << "\n";
		}
		else if(z == "suki?") {
			sort(algo.begin(), algo.end(), compare);
			cout << algo[1].first << " yori mo " << algo[0].first << "\n";
		}
	}
}
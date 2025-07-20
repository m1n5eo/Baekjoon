#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n;
string temp;
vector<pair<string, int>> word;

bool compare(pair<string, int> a, pair<string, int> b) {
	return a.first < b.first;
}

void solve() {
	vector<pair<string, int>> copy = word;

	for(int i = 0; i < n; i++) {
		int copy_size = copy[i].first.size();
		for(int j = 0; j < copy_size; j++) {
			if(copy[i].first[j] == 'k') copy[i].first[j] = 'c';
			else if(copy[i].first[j] == 'n' && copy[i].first[j+1] == 'g') {
				copy[i].first[j] = 'o';
				copy[i].first.erase(j+1, 1);
				copy_size -= 1;
			}
			else if(copy[i].first[j] == 'o') copy[i].first[j] = 'p';
			else if(copy[i].first[j] == 'p') copy[i].first[j] = 'q';
		}
	}

	sort(copy.begin(), copy.end(), compare);
	for(int i = 0; i < n; i++) cout << word[copy[i].second].first << "\n";
}

int main() {
	FASTIO

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		word.push_back({temp, i});
	}

	solve();
}
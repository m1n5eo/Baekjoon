#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 111
#define MAX 22

int n, temp, result = INF;
vector<vector<int>> stat(MAX, vector<int>(MAX, 0));

int solve(vector<int> start, vector<int> link, int idx) {
	if(start.size() + link.size() >= n) {
		int start_size = start.size();
		int start_stat = 0;

		for(int i = 0; i < start_size; i++) {
			for(int j = i+1; j < start_size; j++) {
				start_stat += stat[start[i]][start[j]];
			}
		}

		int link_size = link.size();
		int link_stat = 0;

		for(int i = 0; i < link_size; i++) {
			for(int j = i+1; j < link_size; j++) {
				link_stat += stat[link[i]][link[j]];
			}
		}

		return abs(link_stat - start_stat);
	}
	else {
		start.push_back(idx);
		int ss = solve(start, link, idx+1);
		start.pop_back();

		link.push_back(idx);
		int ll = solve(start, link, idx+1);
		link.pop_back();

		return min(ss, ll);
	}
}

int main() {
	FASTIO

	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> temp;
			stat[i][j] = temp;

			if(i > j) {
				stat[j][i] += stat[i][j];
				stat[i][j] = stat[j][i];
			}
		}
	}

	cout << solve({}, {}, 1);
}
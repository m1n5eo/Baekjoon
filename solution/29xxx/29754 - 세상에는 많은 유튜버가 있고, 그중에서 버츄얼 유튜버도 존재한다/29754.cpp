#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 364

struct type {
	int count[MAX/7] = {0, };
	int time[MAX/7] = {0, };
};

int find_time(string time) {
	int hour = (time[0]-'0')*10 + (time[1]-'0');
	int minute = (time[3]-'0')*10 + (time[4]-'0');

	return hour*60 + minute;
}

int main() {
	FASTIO

	int n, m, b;
	string name, c, d;
	vector<string> result;
	map<string, type> youtuber;

	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		cin >> name >> b >> c >> d;

		int day = b-1;
		int start = find_time(c);
		int stop = find_time(d);

		youtuber[name].count[day/7] += 1;
		youtuber[name].time[day/7] += (stop - start);
	}
	
	for(pair<string, type> ytb : youtuber) {
		int cnt = 0;

		for(int day = 0; day < m/7; day++) {
			if(ytb.second.count[day] >= 5 && ytb.second.time[day] >= 60*60) cnt += 1;
			else break;
		}

		if(cnt == m/7) {
			result.push_back(ytb.first);
		}
	}

	if(result.size() == 0) cout << -1;
	else {
		sort(result.begin(), result.end());
		for(auto name : result) cout << name << "\n";
	}
}
#include <iostream>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct compare {
	bool operator() (pair<int, int> &x, pair<int, int> &y) {
		if(x.first != y.first) return x.first < y.first;
		else return x.second > y.second;
	}
};

int main() {
	FASTIO
	
	int n, a, b;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> player;

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		player.push({a, b});
	}
	
	for(int i = 0; i < 4; i++) {
		player.pop();
	}

	int result = 0;
	pair<int, int> five = player.top();
	player.pop();

	while(player.size()) {
		if(player.top().first == five.first) result += 1;
		else break;
		
		player.pop();
	}

	cout << result;
}
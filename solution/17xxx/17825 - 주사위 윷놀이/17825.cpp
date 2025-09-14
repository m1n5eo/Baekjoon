#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n = 10, temp;
vector<int> go;
vector<bool> visit(33, false);
vector<pair<int, int>> node; // element : node[index] = score, next

int recursion(vector<int> now, int turn, int score) {
	if(turn > 9) return score;
	// cout << now[0] << " " << now[1] << " " << now[2] << " " << now[3] << " | " << turn << " " << score << "\n";
	int ret = 0;
	for(int i = 0; i < 4; i++) {
		if(now[i] != 21) {
			int next = now[i], imsi = now[i];
			for(int j = 0; j < go[turn]; j++) {
				if(j == 0 && next == 5) next = 22;
				else if(j == 0 && next == 10) next = 28;
				else if(j == 0 && next == 15) next = 30;
				else next = node[next].second;
			}
			if(next != 21 && visit[next] == true) continue;
			now[i] = next;
			visit[next] = true;
			visit[imsi] = false;
			ret = max(ret, recursion(now, turn+1, score+node[next].first));
			now[i] = imsi;
			visit[next] = false;
			visit[imsi] = true;
		}
	}
	return ret;
}

int solve() {
	for(int i = 0; i <= 20; i++) node.push_back({i*2, i+1});
	node.push_back({21*0, 21});
	for(int i = 22; i <= 24; i++) node.push_back({i*3-53, i+1});
	for(int i = 25; i <= 26; i++) node.push_back({i*5-100, i+1});
	node.push_back({27*5-100, 20});
	node.push_back({28*2-34, 29});
	node.push_back({29*2-34, 25});
	for(int i = 30; i <= 31; i++) node.push_back({i*(-1)+58, i+1});
	node.push_back({32*(-1)+58, 25});

	return recursion({0, 0, 0, 0}, 0, 0);
}

int main() {
	FASTIO

	for(int i = 0; i < n; i++) {
		cin >> temp;
		go.push_back(temp);
	}
	cout << solve();
}
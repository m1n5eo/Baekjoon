#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55

int n, m;
pair<int, int> temp;
vector<vector<int>> board;
vector<vector<bool>> check;
vector<pair<int, int>> blizzard;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int solve() {
	int k = 7;
	vector<vector<int>> dir(4, vector<int>(0));
	for(int i = 0; i < n/2; i++) {
		for(int j = 0; j < 4; j++) dir[j].push_back((i != 0? dir[j][i-1]:0) + k-j*2);
		k += 8;
	}
	vector<int> straight(n*n, -1);
	int x = 0, y = 0, idx = n*n-1, sw = 1;
	while(idx >= 0) {
		straight[idx] = board[x][y]; idx -= 1;
		check[x][y] = true;
		int nx = x+dx[sw], ny = y+dy[sw]; 
		if(!(0 <= nx && nx < n && 0 <= ny && ny < n) || check[nx][ny] == true) {
			sw = (sw+1)%4;
			nx = x+dx[sw], ny = y+dy[sw];
		}
		x = nx, y = ny;
	}
	for(int i = n*n-1; i >= 1; i--) if(straight.back() == 0) straight.pop_back();
	// cout << "\n" << "straight " << straight.size() << " : "; for(int s : straight) cout << s << " "; cout << "\n";
	int ret = 0;
	for(int turn = 0; turn < m; turn++) {
		// cout << "\n" << "------------turn" << turn << "------------";
		int straight_size = straight.size();
		for(int i = 0; i < blizzard[turn].second; i++) {
			if(dir[blizzard[turn].first][i]-i >= straight_size) break;
			straight.erase(straight.begin() + dir[blizzard[turn].first][i]-i);
			straight_size -= 1;
		}
		// cout << "\n" << "straight " << straight.size() << " : "; for(int s : straight) cout << s << " ";
		// cout << "\n" << "ret : " << ret << "\n";
		sw = 1;
		while(sw) {
			sw = 0; x = 0, y = 0;
			int straight_size = straight.size();
			for(int i = 1; i < straight_size; i++) {
				if(straight[i-1] == straight[i]) y = i;
				else if(straight[i-1] != straight[i]) {
					if(y-x+1 > 3) {
						for(int p = x; p <= y; p++) {
							ret += straight[x];
							straight.erase(straight.begin() + x);
						}
						straight_size -= (y-x+1); i -= (y-x+1);
						sw += 1;
					}
					x = i; y = i;
				}
			}
			if(y-x+1 > 3) {
				for(int p = x; p <= y; p++) {
					ret += straight[x];
					straight.erase(straight.begin() + x);
				}
				sw += 1;
			}
		}
		// cout << "\n" << "straight " << straight.size() << " : "; for(int s : straight) cout << s << " ";
		// cout << "\n" << "ret : " << ret << "\n";
		vector<int> imsi(1, 0);
		x = 1; y = 1;
		straight_size = straight.size();
		for(int i = 1; i < straight_size && imsi.size() < n*n+2; i++) {
			if(straight[i-1] == straight[i]) y = i;
			else if(i != 1 && straight[i-1] != straight[i]) {
				imsi.push_back(y-x+1);
				imsi.push_back(straight[i-1]);
				x = i; y = i;
			}
		}
		if(straight_size > 1) {
			imsi.push_back(y-x+1);
			imsi.push_back(straight.back());
		}
		int imsi_size = imsi.size();
		for(int i = 0; i < imsi_size-n*n; i++) imsi.pop_back();
		straight = imsi;
		// cout << "\n" << "straight " << straight.size() << " : "; for(int s : straight) cout << s << " ";
		// cout << "\n" << "ret : " << ret << "\n";
	}
	return ret;
}

int main() {
	FASTIO

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		board.push_back(vector<int>(0));
		check.push_back(vector<bool>(0));
		for(int j = 0; j < n; j++) {
			cin >> temp.first;
			board[i].push_back(temp.first);
			check[i].push_back(false);
		}
	}
	for(int i = 0; i < m; i++) {
		cin >> temp.first >> temp.second;
		if(temp.first == 1) blizzard.push_back({0, temp.second});
		else if(temp.first == 2) blizzard.push_back({2, temp.second});
		else if(temp.first == 3) blizzard.push_back({3, temp.second});
		else if(temp.first == 4) blizzard.push_back({1, temp.second});
	}
	cout << solve();
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define x first
#define y second
#define MAX 55

int n, direction = 2;
pair<int, int> now, small, big;
string moving;
vector<vector<bool>> maze(MAX*2, vector<bool>(MAX*2, false));

int main() {
	FASTIO

	cin >> n;
	cin >> moving;

	now.x = MAX, now.y = MAX;
	small.x = MAX, small.y = MAX;
	big.x = MAX, big.y = MAX;

	maze[now.x][now.y] = true;

	for(auto m : moving) {
		if(m == 'R') direction = (direction + 1 + 4) % 4;
		else if(m == 'L') direction = (direction - 1 + 4) % 4;
		else if(m == 'F') {
			if(direction == 0) {
				now.x -= 1;
				small.x = min(small.x, now.x);
			}
			else if(direction == 1) {
				now.y += 1;
				big.y = max(big.y, now.y);
			}
			else if(direction == 2) {
				now.x += 1;
				big.x = max(big.x, now.x);
			}
			else if(direction == 3) {
				now.y -= 1;
				small.y = min(small.y, now.y);
			}

			maze[now.x][now.y] = true;
		}
	}

	for(int i = small.x; i <= big.x; i++) {
		for(int j = small.y; j <= big.y; j++) {
			cout << (maze[i][j]? '.' : '#');
		}
		cout << "\n";
	}
}
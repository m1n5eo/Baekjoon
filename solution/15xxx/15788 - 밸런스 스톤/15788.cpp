#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 555

int main() {
	FASTIO

	int n, x, y;
	lli total = 0;
	vector<vector<lli>> stone(MAX, vector<lli>(MAX, 0));

	cin >> n;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> stone[i][j];

			if(stone[i][j] == 0) {
				x = i;
				y = j;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			stone[i][n] += stone[i][j];
			stone[n][j] += stone[i][j];

			total = max(total, stone[i][n]);
			total = max(total, stone[n][j]);
		}
	}
	
	for(int i = 0; i < n; i++) {
		stone[n][n] += stone[i][i];
		stone[n+1][n+1] += stone[i][n-i-1];

		total = max(total, stone[n][n]);
	}

	lli result = total - stone[x][n];
	bool check = true;

	stone[x][n] += result;
	stone[n][y] += result;

	if(x == y) stone[n][n] += result;
	if(x+y == n-1) stone[n+1][n+1] += result;
	
	for(int i = 0; i <= n; i++) {
		if(stone[i][n] != total) check = false;
		if(stone[n][i] != total) check = false;
	}

	if(stone[n][n] != total || stone[n+1][n+1] != total) check = false;

	cout << (check == true? result : -1);
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, temp;
vector<int> cnt(7, 0);

string solve() {
	for(int b = 0; b <= cnt[1]; b++)
		for(int c = 0; c <= cnt[2]; c++)
			for(int d = 0; d <= cnt[3]; d++)
				for(int e = 0; e <= cnt[4]; e++)
					for(int f = 0; f <= cnt[5]; f++)
						for(int g = 0; g <= cnt[6]; g++)
							if((b*1 + c*2 + d*3 + e*4 + f*5 + g*6)%7 == 4)
								return "YES";
	return "NO";
}

int main() {
	FASTIO

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		cnt[temp%7] += 1;
	}
	cout << solve();
}
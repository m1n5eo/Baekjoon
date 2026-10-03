#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

string isbn;
int sum = 0, idx;

int solve() {
	for(int i = 0; i < 13; i++) {
		if(isbn[i] == '*') idx = i;
		else {
			if(i%2 == 0) sum += isbn[i]-'0';
			else sum += (isbn[i]-'0')*3;
		}
	}

	for(int i = 0; i <= 9; i++) {
		if(idx%2 == 0 && (sum+i)%10 == 0) return i;
		else if(idx%2 == 1 && (sum+i*3)%10 == 0) return i;
	}
}

int main() {
	FASTIO

	cin >> isbn;
	cout << solve();
}
#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 55

int n, red, green, blue;
vector<lli> factorial(1, 1);

lli possibility(int floor, int r, int g, int b) {
	return factorial[floor] / factorial[r] / factorial[g] / factorial[b];
}

lli solve(int floor, int r, int g, int b) {
	if(floor > n) return 1;

	lli ret = 0;

	if(red-r >= floor) ret += solve(floor+1, r+floor, g, b);
	if(green-g >= floor) ret += solve(floor+1, r, g+floor, b);
	if(blue-b >= floor) ret += solve(floor+1, r, g, b+floor);

	if(floor%2 == 0) {
		lli p = possibility(floor, floor/2, floor/2, 0);
		if(red-r >= floor/2 && green-g >= floor/2) ret += p*solve(floor+1, r+floor/2, g+floor/2, b);
		if(red-r >= floor/2 && blue-b >= floor/2) ret += p*solve(floor+1, r+floor/2, g, b+floor/2);
		if(green-g >= floor/2 && blue-b >= floor/2) ret += p*solve(floor+1, r, g+floor/2, b+floor/2);
	}

	if(floor%3 == 0) {
		lli p = possibility(floor, floor/3, floor/3, floor/3);
		if(red-r >= floor/3 && green-g >= floor/3 && blue-b >= floor/3) ret += p*solve(floor+1, r+floor/3, g+floor/3, b+floor/3);
	}
	
	return ret;
}

int main() {
	FASTIO

	for(int i = 1; i <= 10; i++) {
		factorial.push_back(factorial.back() * i);
	}

	cin >> n >> red >> green >> blue;
	cout << solve(1, 0, 0, 0);
}
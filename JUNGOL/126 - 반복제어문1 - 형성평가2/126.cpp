#include <iostream>
using namespace std;

int main() {
	int n, cnt1 = 0, cnt2 = 0;
	while(1) {
		cin >> n;
		if(n == 0) break;
		else if(n%2 == 1) cnt1 += 1;
		else if(n%2 == 0) cnt2 += 1;
	}
	cout << "odd : " << cnt1 << "\n";
	cout << "even : " << cnt2;
}
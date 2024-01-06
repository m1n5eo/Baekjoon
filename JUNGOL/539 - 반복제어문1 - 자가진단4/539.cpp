#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num, sum = 0, cnt = 0;
	while(1) {
		cin >> num;
		sum += num;
		cnt += 1;
		if(num > 99) break;
	}
	cout << sum << "\n";
	cout << round((double)sum/(double)cnt * 10)/10 << "\n";
}
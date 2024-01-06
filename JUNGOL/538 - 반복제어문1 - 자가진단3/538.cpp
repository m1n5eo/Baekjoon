#include <iostream>
using namespace std;

int main() {
	int n;
	while(1) {
		cout << "number? ";
		cin >> n;
		if(n == 0) break;
		else if(n > 0) cout << "positive integer" << "\n";
		else if(n < 0) cout << "negative number" << "\n";
	}
}
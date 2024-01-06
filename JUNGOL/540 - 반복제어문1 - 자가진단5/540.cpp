#include <iostream>
using namespace std;

int main() {
	int num;
	while(1) {
		cin >> num;
		if(num == -1) break;
		else if(num%3) {
			continue;
		}
		cout << num/3 << "\n";
	}
}
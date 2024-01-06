#include <iostream>
using namespace std;

int main() {
	int num;
	while(1) {
		cout << "1. Korea" << "\n";
		cout << "2. USA" << "\n";
		cout << "3. Japan" << "\n";
		cout << "4. China" << "\n";
		cout << "number? ";

		cin >> num;

		if(num == 1) cout << "\n" << "Seoul" << "\n\n";
		else if(num == 2) cout << "\n" << "Washington" << "\n\n";
		else if(num == 3) cout << "\n" << "Tokyo" << "\n\n";
		else if(num == 4) cout << "\n" << "Beijing" << "\n\n";
		else {
			cout << "\n" << "none";
			break;
		}
	}
}
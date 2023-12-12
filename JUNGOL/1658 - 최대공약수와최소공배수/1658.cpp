#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int small  = min(n, m), large = max(n, m);
	for(int i = small; i >= 1; i--) {
		if(n%i == 0 && m%i == 0) {
			cout << i << "\n";
			break;
		}
	}
	for(int i = 1; ; i++) {
		if((large*i)%small == 0) {
			cout << max(n, m)*i;
			break;
		}
	}
}

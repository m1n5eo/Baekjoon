#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n;
string name;
float cm;
vector<string> result;

int main() {
	FASTIO

	while(cin >> n) {
		if(n == 0) break;
		float now = 0.0;
		for(int i = 0; i < n; i++) {
			cin >> name >> cm;
			if(now < cm) {
				now = cm;
				result.clear();
				result.push_back(name);
			}
			else if(now == cm) result.push_back(name);
		}
		for(string r: result) cout << r << " ";
		cout << "\n";
	}
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

bool compare(char a, char b) {
	return a > b;
}

int main() {
	FASTIO

	int n, k;
	char temp;
	string str, copy, result = "";
	vector<int> gap;

	cin >> n;
	cin >> str;
	
	copy = str;
	sort(copy.begin(), copy.end(), compare);
	
	for(int i = 0; i < n; i++) {
		if(str[i] != copy[i]) {
			k = i;
			temp = copy[i];
			break;
		}
	}

	for(int i = 0; i < n; i++) {
		if(str[i] == temp) {
			gap.push_back(i);
		}
	}

	for(int g : gap) {
		copy = str;
		for(int i = 0; i < (g - k + 1) / 2; i++) swap(copy[k + i], copy[g - i]);
		result = (result < copy || result == ""? copy : result);
	}

	cout << (gap.size() != 0? result : str);
}
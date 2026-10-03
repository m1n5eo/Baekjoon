#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n;
string temp;
vector<string> word;

int main() {
	FASTIO

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		word.push_back(temp);
	}
	
	for(int i = 0; i < n; i++) cout << word[i] << "DORO" << " ";
}
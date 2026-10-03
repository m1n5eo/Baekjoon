#include <iostream> // BOJ 2916
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 444

int n, m, temp;
vector<int> check(MAX, false);

int main() {
	FASTIO

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		for(int j = 0; j < 360; j++) check[(temp*j)%360] = true;
		for(int j = 0; j < 360; j++) {
			if(check[j] == true) {
				for(int k = 0; k < 360; k++) {
					check[(j + temp*k) % 360] = true;
					check[(j - temp*k + 3600000) % 360] = true;
				}
			}
		}
	}

	for(int i = 0; i < m; i++) {
		cin >> temp;
		cout << (check[temp] == true? "YES" : "NO") << "\n";
	}
}
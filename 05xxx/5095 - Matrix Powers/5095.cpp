#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define vvi vector<vector<int>>
#define vi vector<int>


int n, m, p, temp;
vvi matrix, init, zero;

vvi calculate(vvi a, vvi b) {
	vvi rtn = zero;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				rtn[i][j] = (rtn[i][j] + a[i][k]*b[k][j]) % m;
			}
		}
	}

	return rtn;
}

vvi expo(vvi matrix, int p) {
	if(p <= 1) return (p == 1? matrix : init);
	else {
		vvi e = expo(matrix, p/2);
		return (p%2 == 0? calculate(e, e) : calculate(calculate(e, e), matrix));
	}
}

int main() {
	FASTIO

	while(true) {
		cin >> n >> m >> p;
		
		if(n == 0 && m == 0 && p == 0) {
			break;
		}

		for(int i = 0; i < n; i++) {
			matrix.push_back(vi(0));
			init.push_back(vi(0));
			zero.push_back(vi(0));

			for(int j = 0; j < n; j++) {
				cin >> temp;

				matrix[i].push_back(temp);
				init[i].push_back(1);
				zero[i].push_back(0);
			}
		}

		vvi result = expo(matrix, p);

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << result[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";

		matrix.clear();
		init.clear();
		zero.clear();
	}
}
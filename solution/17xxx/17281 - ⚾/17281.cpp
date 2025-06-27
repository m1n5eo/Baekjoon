#include <iostream> // BOJ 17281
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55

int n, result, temp;
vector<vector<int>> now(MAX, vector<int>(10, 0));

void f(int count, vector<int> rotate, vector<bool> check) {
	if(count == 9) {
		int index = 0, score = 0;

		for(int round = 1; round <= n; round++) {
			vector<bool> ruta(4, false);
			int out = 0;

			for(; out < 3; index++) {
				index = index % 9;

				if(now[round][rotate[index]] == 0) {
					out += 1;
				}
				else if(now[round][rotate[index]] == 1) {
					if(ruta[3] == true) {
						ruta[3] = false;
						score += 1;
					}
					if(ruta[2] == true) {
						ruta[2] = false;
						ruta[3] = true;
					}
					if(ruta[1] == true) {
						ruta[1] = false;
						ruta[2] = true;
					}
					ruta[1] = true;
				}
				else if(now[round][rotate[index]] == 2) {
					if(ruta[3] == true) {
						ruta[3] = false;
						score += 1;
					}
					if(ruta[2] == true) {
						ruta[2] = false;
						score += 1;
					}
					if(ruta[1] == true) {
						ruta[1] = false;
						ruta[3] = true;
					}
					ruta[2] = true;
				}
				else if(now[round][rotate[index]] == 3) {
					if(ruta[3] == true) {
						ruta[3] = false;
						score += 1;
					}
					if(ruta[2] == true) {
						ruta[2] = false;
						score += 1;
					}
					if(ruta[1] == true) {
						ruta[1] = false;
						score += 1;
					}
					ruta[3] = true;
				}
				else if(now[round][rotate[index]] == 4) {
					score += (ruta[1] + ruta[2] + ruta[3] + 1);
					ruta = {false, false, false, false};
				}
			}
		}

		result = max(result, score);
		return;
	}
	else {
		if(count == 3) {
			rotate.push_back(1);
			check[1] = true;

			f(count+1, rotate, check);

			rotate.pop_back();
			check[1] = false;
		}
		else {
			for(int i = 2; i <= 9; i++) {
				if(check[i] == false) {
					rotate.push_back(i);
					check[i] = true;

					f(count+1, rotate, check);

					rotate.pop_back();
					check[i] = false;
				}
			}
		}
	}
}

int main() {
	FASTIO

	cin >> n;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 9; j++) {
			cin >> temp;
			now[i][j] = temp;
		}
	}

	f(0, vector<int>(0), vector<bool>(10, false));

	cout << result;
}
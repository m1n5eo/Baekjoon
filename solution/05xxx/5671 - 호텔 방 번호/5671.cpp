#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, m;

int check(int number) {
	vector<bool> visit(11, false);
	while(number) {
		if(visit[number%10] == true) return 0;
		visit[number%10] = true;
		number /= 10;
	}
	return 1;
}

int main() {
	FASTIO

	while(cin >> n >> m) {
		int result = 0;
		for(int room = n; room <= m; room++) result += check(room);
		cout << result << "\n";
	}
}
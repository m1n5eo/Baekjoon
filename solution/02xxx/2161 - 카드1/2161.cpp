#include <iostream>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, temp;
queue<int> q;

int main() {
	FASTIO

	cin >> n;
	for(int i = 1; i <= n; i++) q.push(i);
	for(int i = 1; i <= n; i++) {
		cout << q.front() << " ";
		q.pop();
		q.push(q.front());
		q.pop();
	}
}
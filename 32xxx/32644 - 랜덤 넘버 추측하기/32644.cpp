#include <iostream> // BOJ 14727
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 555555

int n, m, draw;
vector<int> v(MAX, 0), tree(MAX*4, 0);

int init(int start, int end, int node) {
	if(start == end) return tree[node] = v[start];

	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

int segment(int start, int end, int node, int left, int right) {
	if(left <= start && end <= right) return tree[node];
	else if(end < left || right < start) return 0;

	int mid = (start + end) / 2;
	return segment(start, mid, node*2, left, right) + segment(mid+1, end, node*2+1, left, right);
}

int update(int start, int end, int node, int index, int value) {
	if(index < start || end < index) return tree[node];
	else if(start == end) {
		v[index] = value;
		return tree[node] = value;
	}

	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, node*2, index, value) + update(mid+1, end, node*2+1, index, value);
}

int main() {
	FASTIO

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	init(0, n-1, 1);

	for(int i = 0; i < m; i++) {
		cin >> draw;
		cout << segment(0, n-1, 1, 0, draw-1) << " ";
		update(0, n-1, 1, draw-1, 0);
	}
}
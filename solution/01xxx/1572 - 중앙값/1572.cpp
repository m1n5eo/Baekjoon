#include <iostream> // BOJ 1572
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 66666

lli n, k, temp;
vector<lli> sequence, v(MAX, 0), tree(MAX*4, 0);

lli init(lli start, lli end, lli node) {
	if(start == end) return tree[node] = v[start];
	lli mid = (start+end)/2;
	return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

lli segment(lli start, lli end, lli node, lli index) {
	if(start == end) return start;
	lli mid = (start+end)/2;
	if(index <= tree[node*2]) return segment(start, mid, node*2, index);
	else return segment(mid+1, end, node*2+1, index-tree[node*2]);
}

lli update(lli start, lli end, lli node, lli index, lli diff) {
	if(index < start || index > end) return tree[node];
	else if(start == end) return tree[node] += diff;
	lli mid = (start+end)/2;
	return tree[node] = update(start, mid, node*2, index, diff) + update(mid+1, end, node*2+1, index, diff);
}

lli solve() {
	lli ret = 0;
	for(lli i = 0; i < k-1; i++) v[sequence[i]] += 1;
	init(0, MAX-1, 1);
	for(lli i = k-1; i < n; i++) {
		update(0, MAX-1, 1, sequence[i], 1);
		v[sequence[i]] += 1;
		ret += segment(0, MAX-1, 1, (k+1)/2);
		update(0, MAX-1, 1, sequence[i-k+1], -1);
		v[sequence[i-k+1]] -= 1;
	}
	return ret;
}

int main() {
	FASTIO

	cin >> n >> k;
	for(lli i = 0; i < n; i++) {
		cin >> temp;
		sequence.push_back(temp);
	}
	cout << solve();
}
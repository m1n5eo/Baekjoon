#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 111111

lli n, m, x, y, a, b;
vector<lli> v(MAX, 0), tree(MAX*4, 0);

lli init(lli node, lli start, lli end) {
    if(start == end) return tree[node] = v[start];

    lli mid = (start+end)/2;
    return tree[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end);
}

lli segment(lli node, lli start, lli end, lli left, lli right) {
    if(left > end || right < start) return 0;
    else if(left <= start && end <= right) return tree[node];

    lli mid = (start+end)/2;
    return segment(node*2, start, mid, left, right) + segment(node*2+1, mid+1, end, left, right);
}

lli update(lli node, lli start, lli end, lli index, lli diff) {
    if(index < start || index > end) return tree[node];
    if(start == end) return tree[node] += diff;

    lli mid = (start+end)/2;
    return tree[node] = update(node*2, start, mid, index, diff) + update(node*2+1, mid+1, end, index, diff);
}

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    init(1, 1, n);

    for(int i = 1; i <= m; i++) {
        cin >> x >> y >> a >> b;

        if(x > y) {
            swap(x, y);
        }

        cout << segment(1, 1, n, x, y) << "\n";

        update(1, 1, n, a, b-v[a]);
        v[a] = b;
    }
}
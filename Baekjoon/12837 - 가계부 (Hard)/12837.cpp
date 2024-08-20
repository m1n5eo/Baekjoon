#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 1111111

vector<lli> v(MAX, 0), tree(MAX*4, 0);

lli segment(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    else if(left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;
    return segment(start, mid, node*2, left, right) + segment(mid+1, end, node*2+1, left, right);
}

lli update(int start, int end, int node, int index, lli diff) {
    if(index < start || index > end) return tree[node];
    else if(start == end) return tree[node] += diff;

    int mid = (start+end)/2;
    return tree[node] = update(start, mid, node*2, index, diff) + update(mid+1, end, node*2+1, index, diff);
}

int main() {
    FASTIO

    int n, q, mode;
    lli a, b;

    cin >> n >> q;

    for(int _ = 0; _ < q; _++) {
        cin >> mode >> a >> b;

        if(mode == 1) update(1, n, 1, a, b);
        else if(mode == 2) cout << segment(1, n, 1, a, b) << "\n";
    }
}
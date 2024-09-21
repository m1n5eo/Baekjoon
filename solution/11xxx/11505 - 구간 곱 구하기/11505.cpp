#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MOD 1000000007
#define MAX 1111111

lli n, m, k;
vector<lli> v(MAX, 0), tree(MAX*4, 0);

lli init(lli start, lli end, lli node) {
    if(start == end) return tree[node] = v[start];

    lli mid = (start+end)/2;
    return tree[node] = (init(start, mid, node*2) * init(mid+1, end, node*2+1)) % MOD;
}

lli segment(lli start, lli end, lli node, lli left, lli right) {
    if(left > end || right < start) return 1;
    else if(left <= start && end <= right) return tree[node];

    lli mid = (start+end)/2;
    return (segment(start, mid, node*2, left, right) * segment(mid+1, end, node*2+1, left, right)) % MOD;
}

lli update(lli start, lli end, lli node, lli index, lli change) {
    if(index < start || index > end) return tree[node];
    if(start == end) {
        if(v[index] != 0) return tree[node] = (tree[node] / v[index] * change) % MOD;
        else return tree[node] = change;
    }

    lli mid = (start+end)/2;
    return tree[node] = (update(start, mid, node*2, index, change) * update(mid+1, end, node*2+1, index, change)) % MOD;
}

int main() {
    FASTIO

    cin >> n >> m >> k;

    for(lli i = 0; i < n; i++) {
        cin >> v[i];
    }

    init(0, n-1, 1);

    for(lli i = 0; i < m+k; i++) {
        lli mode, a, b;

        cin >> mode >> a >> b;

        if(mode == 1) {
            update(0, n-1, 1, a-1, b);
            v[a-1] = b;
        }
        else if(mode == 2) {
            cout << segment(0, n-1, 1, a-1, b-1) << "\n";
        }
    }
}
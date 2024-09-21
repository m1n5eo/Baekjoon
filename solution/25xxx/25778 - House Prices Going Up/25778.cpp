#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 555555

vector<lli> v(MAX, 0), tree(MAX*4, 0);

lli init(int start, int end, int node) {
    if(start == end) return tree[node] = v[start];

    int mid = (start+end)/2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

lli segment(int start, int end, int node, int left, int right) {
    if(end < left || right < start) return 0;
    else if(left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;
    return segment(start, mid, node*2, left, right) + segment(mid+1, end, node*2+1, left, right);
}

lli update(int start, int end, int node, int index, lli value) {
    if(index < start || end < index) return tree[node];
    else if(start == end) return tree[node] += value;

    int mid = (start+end)/2;
    return tree[node] = update(start, mid, node*2, index, value) + update(mid+1, end, node*2+1, index, value);
}

int main() {
    FASTIO

    int n, m;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    init(1, n, 1);

    cin >> m;

    for(int _ = 0; _ < m; _++) {
        char mode;
        lli a, b;

        cin >> mode >> a >> b;

        if(mode == 'R') cout << segment(1, n, 1, a, b) << "\n";
        else if(mode == 'U') {
            update(1, n, 1, a, b);
            v[a] += b;
        }
    }
}
#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111
#define INF 2100000000

int n, m;
vector<int> v(MAX, 0), tree(MAX*4, 0);

int init(int start, int end, int node) {
    if(start == end) return tree[node] = v[start];

    int mid = (start+end)/2;
    return tree[node] = min(init(start, mid, node*2), init(mid+1, end, node*2+1));
}

int segment(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return INF;
    else if(left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;
    return min(segment(start, mid, node*2, left, right), segment(mid+1, end, node*2+1, left, right));
}

int update(int start, int end, int node, int index, int change) {
    if(index < start || index > end) return tree[node];
    if(start == end) return tree[node] = change;

    int mid = (start+end)/2;
    return tree[node] = min(update(start, mid, node*2, index, change), update(mid+1, end, node*2+1, index, change));
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    init(0, n-1, 1);

    cin >> m;

    for(int i = 0; i < m; i++) {
        int mode, a, b;
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
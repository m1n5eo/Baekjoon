#include <bits/stdc++.h>
using namespace std;

int n, m, k, sw;
long long a, b, c, arr[1234567], tree[4*1234567], lazy[4*1234567];

long long int init(int node, int start, int end) {
    if(start == end) return tree[node] = arr[start];
    int mid = (start+end)/2;
    return tree[node] = init(node*2, start, mid)+init(node*2+1, mid+1, end);
}

void updateLazy(int node, int start, int end) {
    if(lazy[node] != 0) {
        tree[node] = tree[node] + (end-start+1) * lazy[node];
        if(start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right, long long int value) {
    updateLazy(node, start, end);
    if(right < start || left > end) return;
    if(left <= start && end <= right) {
        tree[node] = tree[node] + (end-start+1) * value;
        if(start != end) {
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, left, right, value);
    update(node*2+1, mid+1, end, left, right, value);
    tree[node] = tree[node*2]+tree[node*2+1];
}

long long int sum(int node, int start, int end, int left, int right) {
    updateLazy(node, start, end);
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start+end)/2;
    return sum(node*2, start, mid, left, right)+sum(node*2+1, mid+1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);
    for(int i = 0; i < m+k; i++) {
        cin >> sw;
        if(sw == 1) {
            cin >> a >> b >> c;
            update(1, 1, n, a, b, c);
        }
        else if(sw == 2) {
            cin >> a >> b;
            cout << sum(1, 1, n, a, b) << '\n';
        }
    }
}
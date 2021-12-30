#include <bits/stdc++.h>
using namespace std;

int n, m, s, a, b;
int tree[4*1234567], lazy[4*1234567];

void updateLazy(int node, int start, int end) {
    if(lazy[node] != 0) {
        tree[node] = (end-start+1) - tree[node];
        if(start != end) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right) {
    updateLazy(node, start, end);
    if(right < start || end < left) return;
    if(left <= start && end <= right) {
        tree[node] = (end-start+1) - tree[node];
        if(start != end) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, left, right);
    update(node*2+1, mid+1, end, left, right);
    tree[node] = tree[node*2]+tree[node*2+1];
}

int segment(int node, int start, int end, int left, int right) {
    updateLazy(node, start, end);
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start+end)/2;
    return segment(node*2, start, mid, left, right)+segment(node*2+1, mid+1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> s >> a >> b;
        if(s == 0) update(1, 1, n, a, b);
        else if(s == 1) cout << segment(1, 1, n, a, b) << "\n";
    }
}
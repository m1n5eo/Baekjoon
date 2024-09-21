#include <bits/stdc++.h>
using namespace std;

int n, m, sw, a, b, arr[1000000];
long long int tree[4*1000000];

long long int sum(int node, int start, int end, int left, int right) {
    if(start > right || end < left) return 0;
    else if(left <= start && end <= right) return tree[node];
    int mid = (start+end)/2;
    return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}

void update(int node, int start, int end, int index, long long int dif) {
    if(start > index || end < index) return;
    tree[node] += dif;
    if(start != end) {
        int mid = (start+end)/2;
        update(node*2, start, mid, index, dif);
        update(node*2+1, mid+1, end, index, dif);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> sw >> a >> b;
        if(sw == 0) {
            if(a > b) swap(a, b);
            cout << sum(1, 1, n, a, b) << "\n";
        }
        else if(sw == 1) {
            update(1, 1, n, a, b-arr[a]);
            arr[a] = b;
        }
    }
}
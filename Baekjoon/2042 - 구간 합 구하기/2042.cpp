#include <bits/stdc++.h>
using namespace std;

long long int n, m, k, a, b, sw;
long long int arr[1234567], tree[4*1234567];

long long int init(long long int start, int long long end, long long int node) {
    if(start == end) return tree[node] = arr[start];
    long long int mid = (start+end)/2;
    return tree[node] = init(start, mid, node*2)+init(mid+1, end, node*2+1);
}

long long int segment(long long int start, long long int end, long long int node, long long int left, long long int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    long long int mid = (start+end)/2;
    return segment(start, mid, node*2, left, right)+segment(mid+1, end, node*2+1, left, right);
}

void update(long long int start, long long int end, long long int node, long long int index, long long int dif) {
    if(index < start || index > end) return;
    tree[node] += dif;
    if(start == end) return;
    long long int mid = (start+end)/2;
    update(start, mid, node*2, index, dif);
    update(mid+1, end, node*2+1, index, dif);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    for(long long int i = 0; i < n; i++) cin >> arr[i];
    init(0, n-1, 1);
    for(long long int i = 0; i < m+k; i++) {
        cin >> sw >> a >> b;
        if(sw == 1) {
            update(0, n-1, 1, a-1, b-arr[a-1]);
            arr[a-1] = b;
        }
        else if(sw == 2) cout << segment(0, n-1, 1, a-1, b-1) << '\n';
    }
}
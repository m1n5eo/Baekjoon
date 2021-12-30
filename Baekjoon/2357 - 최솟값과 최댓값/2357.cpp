#include <bits/stdc++.h>
using namespace std;

long long int n, m, k, a, b, sw;
long long int arr[1234567], min_tree[4*1234567], max_tree[4*1234567];

long long int min_init(long long int start, int long long end, long long int node) {
    if(start == end) return min_tree[node] = arr[start];
    long long int mid = (start+end)/2;
    return min_tree[node] = min(min_init(start, mid, node*2), min_init(mid+1, end, node*2+1));
}

long long int max_init(long long int start, int long long end, long long int node) {
    if(start == end) return max_tree[node] = arr[start];
    long long int mid = (start+end)/2;
    return max_tree[node] = max(max_init(start, mid, node*2), max_init(mid+1, end, node*2+1));
}

long long int min_segment(long long int start, long long int end, long long int node, long long int left, long long int right) {
    if(left > end || right < start) return 2100000000;
    if(left <= start && end <= right) return min_tree[node];
    long long int mid = (start+end)/2;
    return min(min_segment(start, mid, node*2, left, right), min_segment(mid+1, end, node*2+1, left, right));
}

long long int max_segment(long long int start, long long int end, long long int node, long long int left, long long int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return max_tree[node];
    long long int mid = (start+end)/2;
    return max(max_segment(start, mid, node*2, left, right), max_segment(mid+1, end, node*2+1, left, right));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(long long int i = 0; i < n; i++) cin >> arr[i];
    min_init(0, n-1, 1);
    max_init(0, n-1, 1);
    for(long long int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << min_segment(0, n-1, 1, a-1, b-1) << ' ' << max_segment(0, n-1, 1, a-1, b-1) << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long int n, m, k, a, b, sw;
long long int arr[1234567], tree[4*1234567];

long long int init(long long int start, int long long end, long long int node) {
    if(start == end) return tree[node] = arr[start]%mod;
    long long int mid = (start+end)/2;
    return tree[node] = (init(start, mid, node*2)*init(mid+1, end, node*2+1))%mod;
}

long long int segment(long long int start, long long int end, long long int node, long long int left, long long int right) {
    if(left > end || right < start) return 1;
    if(left <= start && end <= right) return tree[node]%mod;
    long long int mid = (start+end)/2;
    return (segment(start, mid, node*2, left, right)*segment(mid+1, end, node*2+1, left, right))%mod;
}

long long int update(long long int start, long long int end, long long int node, long long int index, long long int dif) {
    if(index < start || index > end) return tree[node]%mod;
    if(start == end) return tree[node] = dif%mod;
    long long int mid = (start+end)/2;
    return tree[node] = (update(start, mid, node*2, index, dif)*update(mid+1, end, node*2+1, index, dif))%mod;
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
            arr[a-1] = b;
            update(0, n-1, 1, a-1, b);
        }
        else if(sw == 2) {
            if(a > b) swap(a, b);
            cout << segment(0, n-1, 1, a-1, b-1) << '\n';
        }
    }
}
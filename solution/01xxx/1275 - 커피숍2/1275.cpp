#include <stdio.h>
#include <algorithm>
using namespace std;

long long int n, m, x, y, a, b, arr[100001];
long long int tree[4*100001];

long long init(long long int node, long long int start, long long int end) {
    if(start == end) return tree[node] = arr[start];
    long long int mid = (start+end)/2;
    return tree[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end);
}

long long int sum(long long int node, long long int start, long long int end, long long int left, long long int right) {
    if(start > right || end < left) return 0;
    else if(left <= start && end <= right) return tree[node];
    long long int mid = (start+end)/2;
    return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}

void update(long long int node, long long int start, long long int end, long long int index, long long int dif) {
    if(index < start || index > end) return;
    tree[node] += dif;
    if(start == end) return;
    long long int mid = (start+end)/2;
    update(node*2, start, mid, index, dif);
    update(node*2+1, mid+1, end, index, dif);
}

int main() {
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    init(1, 1, n);
    for(int i = 1; i <= m; i++) {
        scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
        if(x > y) swap(x, y);
        printf("%lld\n", sum(1, 1, n, x, y));
        update(1, 1, n, a, b-arr[a]);
        arr[a] = b;
    }
}
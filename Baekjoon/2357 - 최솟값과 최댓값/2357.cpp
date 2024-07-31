#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000000
#define MAX 111111

int n, m;
vector<int> v(MAX, 0), min_tree(MAX*4, INF), max_tree(MAX*4, -INF);

int min_init(int start, int end, int node) {
    if(start == end) return min_tree[node] = v[start];

    int mid = (start+end)/2;
    return min_tree[node] = min(min_init(start, mid, node*2), min_init(mid+1, end, node*2+1));
}

int max_init(int start, int end, int node) {
    if(start == end) return max_tree[node] = v[start];

    int mid = (start+end)/2;
    return max_tree[node] = max(max_init(start, mid, node*2), max_init(mid+1, end, node*2+1));
}

int min_segment(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return INF;
    else if(left <= start && end <= right) return min_tree[node];

    int mid = (start+end)/2;
    return min(min_segment(start, mid, node*2, left, right), min_segment(mid+1, end, node*2+1, left, right));
}

int max_segment(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return -INF;
    else if(left <= start && end <= right) return max_tree[node];

    int mid = (start+end)/2;
    return max(max_segment(start, mid, node*2, left, right), max_segment(mid+1, end, node*2+1, left, right));
}

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    min_init(0, n-1, 1);
    max_init(0, n-1, 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        
        cin >> a >> b;

        cout << min_segment(0, n-1, 1, a-1, b-1) << " " << max_segment(0, n-1, 1, a-1, b-1) << "\n";
    }
}
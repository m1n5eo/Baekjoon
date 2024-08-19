#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1111111
#define MAX 55555

vector<int> v(MAX, 0), tree1(MAX*4, INF), tree2(MAX*4, 0);

int init1(int start, int end, int node) {
    if(start == end) return tree1[node] = v[start];

    int mid = (start+end)/2;
    return tree1[node] = min(init1(start, mid, node*2), init1(mid+1, end, node*2+1));
}

int init2(int start, int end, int node) {
    if(start == end) return tree2[node] = v[start];

    int mid = (start+end)/2;
    return tree2[node] = max(init2(start, mid, node*2), init2(mid+1, end, node*2+1));
}

int segment1(int start, int end, int node, int left, int right) {
    if(end < left || right < start) return INF;
    else if(left <= start && end <= right) return tree1[node];

    int mid = (start+end)/2;
    return min(segment1(start, mid, node*2, left, right), segment1(mid+1, end, node*2+1, left, right));
}

int segment2(int start, int end, int node, int left, int right) {
    if(end < left || right < start) return 0;
    else if(left <= start && end <= right) return tree2[node];

    int mid = (start+end)/2;
    return max(segment2(start, mid, node*2, left, right), segment2(mid+1, end, node*2+1, left, right));
}

int main() {
    FASTIO

    int n, k;

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    init1(1, n, 1);
    init2(1, n, 1);

    for(int i = 0; i < k; i++) {
        int a, b;

        cin >> a >> b;

        cout << segment2(1, n, 1, a, b) - segment1(1, n, 1, a, b) << "\n";
    }
}
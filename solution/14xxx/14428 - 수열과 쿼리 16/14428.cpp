#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define INF 2100000000
#define MAX 111111

int n, m;
vector<int> v(MAX, 0);
vector<pii> tree(MAX*4, {0, 0});

pii init(int start, int end, int node) {
    if(start == end) return tree[node] = {v[start], start};

    int mid = (start+end)/2;
    
    pii f = init(start, mid, node*2);
    pii b = init(mid+1, end, node*2+1);
    
    if(f.first <= b.first) tree[node] = f;
    else tree[node] = b;

    return tree[node];
}

pii segment(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return {INF, -1};
    else if(left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;

    pii f = segment(start, mid, node*2, left, right);
    pii b = segment(mid+1, end, node*2+1, left, right);

    if(f.first <= b.first) return f;
    else return b;
}

pii update(int start, int end, int node, int index, int change) {
    if(index < start || index > end) return tree[node];
    else if(start == end) return tree[node] = {change, index};

    int mid = (start+end)/2;

    pii f = update(start, mid, node*2, index, change);
    pii b = update(mid+1, end, node*2+1, index, change);

    if(f.first <= b.first) return tree[node] = f;
    else return tree[node] = b;
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
            cout << segment(0, n-1, 1, a-1, b-1).second+1 << "\n";
        }
    }
}
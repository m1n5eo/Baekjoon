#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 555555

int n, m, temp, mode, a, b, c;
vector<int> sequence, tree(MAX*4, 0), lazy(MAX*4, 0);
vector<int> result;

int init(int start, int end, int node) {
    if(start == end) {
        tree[node] = sequence[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    tree[node] = init(start, mid, node*2) ^ init(mid+1, end, node*2+1);
    return tree[node];
}

void updateLazy(int start, int end, int node) {
    if(lazy[node] != 0) {
        if(start != end) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }

        tree[node] ^= (end - start + 1) % 2 == 1? lazy[node] : 0;
        lazy[node] = 0;
    }
}

void update(int start, int end, int node, int left, int right, int value) {
    updateLazy(start, end, node);

    if(right < start || end < left) return;
    else if(left <= start && end <= right) {
        if(start != end) {
            lazy[node*2] ^= value;
            lazy[node*2+1] ^= value;
        }

        tree[node] ^= (end - start + 1) % 2 == 1? value : 0;
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, node*2, left, right, value);
    update(mid+1, end, node*2+1, left, right, value);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

int segment(int start, int end, int node, int index) {
    updateLazy(start, end, node);

    if(index < start || end < index) return 0;
    else if(index <= start && end <= index) return tree[node];

    int mid = (start + end) / 2;
    return segment(start, mid, node*2, index) ^ segment(mid+1, end, node*2+1, index);
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        sequence.push_back(temp);
    }

    init(0, n-1, 1);

    cin >> m;

    for(int _ = 0; _ < m; _++) {
        cin >> mode;

        if(mode == 1) {
            cin >> a >> b >> c;
            update(0, n-1, 1, a, b, c);
        }
        else if(mode == 2) {
            cin >> a;
            result.push_back(segment(0, n-1, 1, a));
        }
    }

    for(auto r : result) {
        cout << r << " ";
    }
}
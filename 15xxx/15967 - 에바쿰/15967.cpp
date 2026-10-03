#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 1111111

int n, q1, q2, temp, mode, a, b;
lli c;
vector<int> shock(1, 0);
vector<lli> tree(MAX*4, 0), lazy(MAX*4, 0), result;

void init(int start, int end, int node) {
    if(start == end) {
        tree[node] = shock[start];
        return;
    }

    int mid = (start + end) / 2;
    init(start, mid, node*2);
    init(mid+1, end, node*2+1);
    tree[node] = tree[node*2] + tree[node*2+1];
}

void updateLazy(int start, int end, int node) {
    if(lazy[node] != 0) {
        if(start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }

        tree[node] += (end - start + 1) * lazy[node];
        lazy[node] = 0;
    }
}

void update(int start, int end, int node, int left, int right, int value) {
    updateLazy(start, end, node);

    if(right < start || end < left) return;
    else if(left <= start && end <= right) {
        if(start != end) {
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }

        tree[node] += (end - start + 1) * value;
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, node*2, left, right, value);
    update(mid+1, end, node*2+1, left, right, value);
    tree[node] = tree[node*2] + tree[node*2+1];
}

lli segment(int start, int end, int node, int left, int right) {
    updateLazy(start, end, node);

    if(right < start || end < left) return 0;
    else if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return segment(start, mid, node*2, left, right) + segment(mid+1, end, node*2+1, left, right);
}

int main() {
    FASTIO

    cin >> n >> q1 >> q2;

    for(int _ = 1; _ <= n; _++) {
        cin >> temp;
        shock.push_back(temp);
    }

    init(1, n, 1);

    for(int _ = 0; _ < q1+q2; _++) {
        cin >> mode;

        if(mode == 1) {
            cin >> a >> b;
            result.push_back(segment(1, n, 1, a, b));
        }
        else if(mode == 2) {
            cin >> a >> b >> c;
            update(1, n, 1, a, b, c);
        }
    }

    for(lli r : result) {
        cout << r << " ";
    }
}
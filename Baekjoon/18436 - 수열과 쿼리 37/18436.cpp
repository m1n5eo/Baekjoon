#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n, m;
vector<int> v(MAX, 0), tree(MAX*4, 0);

int init(int start, int end, int node) {
    if(start == end) {
        if(v[start]%2 == 0) return tree[node] = 1;
        else return tree[node] = 0;
    }

    int mid = (start+end)/2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

int segment(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    else if(left <= start && end<= right) return tree[node];

    int mid = (start+end)/2;
    return segment(start, mid, node*2, left, right) + segment(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, int diff) {
    if(index < start || index > end) return;
    tree[node] += diff;
    if(start == end) return;

    int mid = (start+end)/2;
    update(start, mid, node*2, index, diff);
    update(mid+1, end, node*2+1, index, diff);
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    init(0, n-1, 1);

    cin >> m;

    for(int _ = 0; _ < m; _++) {
        int mode, a, b;
        cin >> mode >> a >> b;

        if(mode == 1) {
            if(v[a-1]%2 == 0 && b%2 == 1) {
                update(0, n-1, 1, a-1, -1);
                v[a-1] = b;
            }
            else if(v[a-1]%2 == 1 && b%2 == 0) {
                update(0, n-1, 1, a-1, 1);
                v[a-1] = b;
            }
        }
        else if(mode == 2) {
            cout << segment(0, n-1, 1, a-1, b-1) << "\n";
        }
        else if(mode == 3) {
            cout << (b-a+1)-segment(0, n-1, 1, a-1, b-1) << "\n";
        }
    }
}
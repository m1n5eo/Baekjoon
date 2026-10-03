#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

vector<int> v(MAX, 0), tree(MAX*4, 0);

int init(int start, int end, int node) {
    if(start == end) return tree[node] = v[start];

    int mid = (start+end)/2;
    return tree[node] = init(start, mid, node*2) * init(mid+1, end, node*2+1);
}

int update(int start, int end, int node, int index, int value) {
    if(index < start || end < index) return tree[node];
    else if(start == end) return tree[node] = value;

    int mid = (start+end)/2;
    return tree[node] = update(start, mid, node*2, index, value) * update(mid+1, end, node*2+1, index, value);
}

int segment(int start, int end, int node, int left, int right) {
    if(end < left || right < start) return 1;
    else if(left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;
    return segment(start, mid, node*2, left, right) * segment(mid+1, end, node*2+1, left, right);
}

int main() {
    FASTIO

    int n, k;

    while(cin >> n >> k) {
        int temp;

        for(int i = 1; i <= n; i++) {
            cin >> temp;

            if(temp > 0) v[i] = 1;
            else if(temp == 0) v[i] = 0;
            else if(temp < 0) v[i] = -1;
        }

        init(1, n, 1);

        char mode;
        int a, b;

        for(int _ = 0; _ < k; _++) {
            cin >> mode >> a >> b;

            if(mode == 'C') {
                if(b > 0) update(1, n, 1, a, 1);
                else if(b == 0) update(1, n, 1, a, 0);
                else if(b < 0) update(1, n, 1, a, -1);
            }
            else if(mode == 'P') {
                int rtn = segment(1, n, 1, a, b);

                if(rtn > 0) cout << "+";
                else if(rtn == 0) cout << "0";
                else if(rtn < 0) cout << "-";
            }
        }

        cout << "\n";
    }
}
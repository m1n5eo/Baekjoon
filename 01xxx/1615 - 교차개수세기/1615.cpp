#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define lli long long int
#define MAX 2222

int n, m, a, b;
lli result = 0;
vector<pii> line;
vector<lli> tree(MAX*4, 0);

void update(int start, int end, int node, int index) {
    if(index < start || end < index) return;
    else if(start == end) {
        tree[node] += 1;
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, node*2, index);
    update(mid+1, end, node*2+1, index);
    tree[node] = tree[node*2] + tree[node*2+1];
}

lli segment(int start, int end, int node, int left, int right) {
    if(end < left || right < start) return 0;
    else if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return segment(start, mid, node*2, left, right) + segment(mid+1, end, node*2+1, left, right);
}

bool compare(pii x, pii y) {
    if(x.first != y.first) return x.first < y.first;
    else return x.second < y.second;
}

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        line.push_back({a, b});
    }

    sort(line.begin(), line.end(), compare);

    for(auto l : line) {
        update(1, n, 1, l.second);
        result += segment(1, n, 1, l.second+1, n);
    }

    cout << result;
}
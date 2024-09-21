#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define lli long long int
#define MAX 555555

int n;
lli result;
vector<pii> v;
vector<int> tree(MAX*4, 0);

bool compare(pii a, pii b) {
    if(a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int cnt(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    else if(left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;
    
    return cnt(start, mid, node*2, left, right) + cnt(mid+1, end, node*2+1, left, right);
}

int update(int start, int end, int node, int index) {
    if(start == end) return tree[node] = 1;

    int mid = (start+end)/2;

    if(index <= mid) update(start, mid, node*2, index);
    else update(mid+1, end, node*2+1, index);

    return tree[node] = tree[node*2] + tree[node*2+1];
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;

        v.push_back({value, i});
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++) {
        if(!(v[i].second+1 > n-1)) {
            result += (lli)cnt(0, n-1, 1, v[i].second+1, n-1);
        }
        update(0, n-1, 1, v[i].second);
    }

    cout << result;
}
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define lli long long int
#define MAX 555555

int n, temp;
lli result = 0;
map<int, int> connect;
vector<int> cable;
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
    if(right < start || end < left) return 0;
    else if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return segment(start, mid, node*2, left, right) + segment(mid+1, end, node*2+1, left, right);
}

int main() {
    FASTIO
    
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> temp;
        connect[temp] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> temp;
        cable.push_back(connect[temp]);
    }

    for(int c : cable) {
        update(1, n, 1, c);
        result += segment(1, n, 1, c+1, n);
    }

    cout << result;
}
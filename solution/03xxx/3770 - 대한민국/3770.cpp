#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define lli long long int
#define MAX 1111

int testcase, n, m, k, a, b;
lli result = 0;
vector<pii> road;
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

int segment(int start, int end, int node, int left, int right) {
    if(right < start || end < left) return 0;
    else if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return segment(start, mid, node*2, left, right) + segment(mid+1, end, node*2+1, left, right);
}

bool compare1(pii x, pii y) {
    if(x.first != y.first) return x.first < y.first;
    else return x.second < y.second;
}

bool compare2(pii x, pii y) {
    if(x.second != y.second) return x.second < y.second;
    else return x.first < y.first;
}

int main() {
    FASTIO

    cin >> testcase;

    for(int tc = 1; tc <= testcase; tc++) {
        cin >> n >> m >> k;

        for(int _ = 0; _ < k; _++) {
            cin >> a >> b;
            road.push_back({a, b});
        }

        if(n < m) {
            sort(road.begin(), road.end(), compare1);

            for(pii r : road) {
                update(1, m, 1, r.second);
                result += segment(1, m, 1, r.second+1, m);
            }
        }
        else {
            sort(road.begin(), road.end(), compare2);

            for(pii r : road) {
                update(1, n, 1, r.first);
                result += segment(1, n, 1, r.first+1, n);
            }
        }

        cout << "Test case " << tc << ": " << result << "\n";

        road.clear();
        result = 0;
        for(int i = 0; i < max(n, m)*4; i++) tree[i] = 0;
    }
}
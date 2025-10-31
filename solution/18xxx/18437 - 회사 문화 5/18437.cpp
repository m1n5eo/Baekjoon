#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100001

int n, m, cnt = 0;
vector<int> init_parent(MAX, 0), tree(MAX*4, 0), lazy(MAX*4, 0);
vector<vector<int>> graph(MAX, vector<int>(0));
vector<pair<int, int>> range(MAX, {-1, -1});

void dfs(int node) {
    range[node].first = cnt++;
    for(int g : graph[node]) dfs(g);
    range[node].second = cnt-1;
}

int init(int node, int start, int end) {
    if(start == end) return tree[node] = 1;
    int mid = (start+end)/2;
    return tree[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end);
}

void updateLazy(int node, int start, int end) {
    if(lazy[node] != 0) {
        if(lazy[node] == 1) tree[node] = end-start+1;
        else if(lazy[node] == -1) tree[node] = 0;
        if(start != end) {
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right, int value) {
    updateLazy(node, start, end);
    if(left > end || right < start) return;
    else if(left <= start && end <= right) {
        lazy[node] = value;
        updateLazy(node, start, end);
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, left, right, value);
    update(node*2+1, mid+1, end, left, right, value);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int segment(int node, int start, int end, int left, int right) {
    updateLazy(node, start, end);
    if(left > end || right < start) return 0;
    else if(left <= start && end <= right) return tree[node];
    int mid = (start+end)/2;
    return segment(node*2, start, mid, left, right) + segment(node*2+1, mid+1, end, left, right);
}

vector<int> solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        graph[temp].push_back(i);
    }
    dfs(0);

    // cout << "\n" << "graph" << "\n";
    // for(int i = 0; i <= n; i++) {
    //     cout << i << " : ";
    //     for(int g : graph[i]) cout << g << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    // cout << "\n" << "range" << "\n";
    // for(int i = 0; i <= n; i++) cout << i << " : " << range[i].first << " " << range[i].second << "\n";
    // cout << "\n";

    vector<int> ret;
    cin >> m;
    init(1, 1, n);
    for(int _ = 0; _ < m; _++) {
        int query, index; cin >> query >> index;
        if(range[index].first != range[index].second) {
            if(query == 1) update(1, 1, n, range[index].first+1, range[index].second, 1);
            else if(query == 2) update(1, 1, n, range[index].first+1, range[index].second, -1);
            else if(query == 3) ret.push_back(segment(1, 1, n, range[index].first+1, range[index].second));
        }
        else if(query == 3) ret.push_back(0);
    }
    return ret;
}

int main() {
    FASTIO
    for(int s : solve()) cout << s << "\n";
}
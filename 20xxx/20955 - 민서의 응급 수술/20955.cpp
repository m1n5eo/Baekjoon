#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

vector<int> parent(MAX, 0);

int Find(int x) {
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a); b = Find(b);
    if(a != b) parent[b] = a;
}

int solve() {
    int n, m, ret = 0;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) parent[i] = i;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if(Find(a) != Find(b)) Union(a, b);
        else ret += 1;
    }

    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(Find(parent[i]));
    return ret+s.size()-1;
}

int main() {
    FASTIO
    cout << solve();
}
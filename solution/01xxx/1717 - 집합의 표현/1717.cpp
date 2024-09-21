#include <iostream>
using namespace std;

#define MAX 1111111

int n, m, mode, a, b, parent[MAX];

int Find(int x) {
    if(x == parent[x]) return x;

    int p = Find(parent[x]);
    parent[x] = p;

    return p;
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return;
    else if(x != y) parent[y] = x;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++) {
        cin >> mode >> a >> b;

        if(mode == 0) {
            Union(a, b);
        }
        else if(mode == 1) {
            a = Find(a);
            b = Find(b);

            if(a == b) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
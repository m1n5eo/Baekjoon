#include <iostream>
using namespace std;

#define MAX 1111

int t, n, m, a, b;
int parent[MAX];

int Find(int x) {
    if(x == parent[x]) return x;

    int p = Find(parent[x]);
    parent[x] = p;

    return p;
}

bool isSame(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return true;
    else return false;
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    for(int _ = 0; _ < t; _++) {
        cin >> n >> m;

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        int cnt = 0;

        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            if(isSame(a, b) == false) {
                Union(a, b);
                cnt += 1;
            }
        }
        
        cout << cnt << "\n";
    }
}
#include <iostream>
using namespace std;

int n, m, start, after, parent[222], arr[222][222];

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
    else parent[y] = x;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) parent[i] = i;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];

            if(arr[i][j] == 1) {
                Union(i, j);
            }
        }
    }

    for(int i = 1; i <= n; i++) parent[i] = Find(i);

    cin >> start;
    for(int _ = 1; _ < m; _++) {
        cin >> after;
        if(parent[start] != parent[after]) {
            cout << "NO";
            exit(0);
        }
    }

    cout << "YES";
}
#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<int> parent;

int Find(int x) {
    if(x == parent[x]) return parent[x];
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool Same(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return true;
    else return false;
}

int main() {
    FASTIO

    int tc;

    cin >> tc;

    for(int testcase = 0; testcase < tc; testcase++) {
        int n, m, a, b;

        cin >> n;

        for(int i = 0; i < n; i++) {
            parent.push_back(i);
        }

        cin >> m;

        for(int _ = 0; _ < m; _++) {
            cin >> a >> b;
            Union(a, b);
        }

        cout << "Scenario " << testcase+1 << ":" << "\n";

        cin >> m;

        for(int _ = 0; _ < m; _++) {
            cin >> a >> b;

            if(Same(a, b) == true) cout << 1 << "\n";
            else cout << 0 << "\n";
        }

        parent.clear();
        cout << "\n";
    }
}
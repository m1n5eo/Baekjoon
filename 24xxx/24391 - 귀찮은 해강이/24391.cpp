#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, m, result;
vector<int> parent, v;

int Find(int x) {
    if(x == parent[x]) return x;
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

    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        parent.push_back(i);
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        Union(a, b);
    }

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);

        if(i != 0) {
            if(Same(v[i-1], v[i]) == false) {
                result += 1;
            }
        }
    }

    cout << result;
}
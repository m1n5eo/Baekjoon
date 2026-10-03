#include <iostream>
using namespace std;

#define MAX 555555

int n, m, x, y, result;
int parent[MAX];

int Find(int a) {
    if(a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
}

bool isSame(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++) {
        cin >> x >> y;

        if(result != 0) continue;

        if(isSame(x, y) == false) Union(x, y);
        else result = i+1;
    }

    cout << result;
    return 0;
}
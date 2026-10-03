#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111
#define ulli unsigned long long int

struct type {
    ulli a, b;
};

ulli n, m, k, stone[MAX], parent[MAX];
bool eliminate[MAX], check[MAX];
vector<type> v;

ulli Find(ulli x) {
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(ulli x, ulli y) {
    x = Find(x);
    y = Find(y);

    if(stone[x] > stone[y]) parent[x] = y;
    else parent[y] = x;
}

bool Same(ulli x, ulli y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return true;
    else return false;
}

int main() {
    FASTIO

    cin >> n >> m >> k;

    for(ulli i = 1; i <= n; i++) {
        cin >> stone[i];
        parent[i] = i;
    }

    for(ulli i = 0; i < m; i++) {
        ulli x, y;
        cin >> x >> y;

        if(min(x,y) == 1 && max(x,y) == n) eliminate[max(x,y)] = true;
        else eliminate[min(x,y)] = true;
    }

    if(m < 2) {
        cout << "YES";
        exit(0);
    }

    for(ulli i = 1; i <= n; i++) {
        if(eliminate[i] == false && i != n) {
            v.push_back({i, i+1});
        }
        else if(eliminate[i] == false && i == n) {
            v.push_back({1, n});
        }
    }

    ulli v_size = v.size();

    for(ulli i = 0; i < v_size; i++) {
        if(Same(v[i].a, v[i].b) == false) {
            Union(v[i].a, v[i].b);
        }
    }

    for(int i = 1; i <= n; i++) parent[i] = Find(i);

    ulli sum = 0;

    for(ulli i = 1; i <= n; i++) {
        if(check[parent[i]] == false) {
            check[parent[i]] = true;
            sum += stone[parent[i]];
        }
    }
    
    if(sum <= k) cout << "YES";
    else cout << "NO";
}
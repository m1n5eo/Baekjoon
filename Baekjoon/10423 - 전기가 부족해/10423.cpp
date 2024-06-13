#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1001

struct type {
    int a, b, cost;
};

int n, m, k, result;
bool power[MAX];
vector<int> parent;
vector<type> v;

bool compare(type a, type b) {
    return a.cost < b.cost;
}

int Find(int x) {
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(power[x] == true) parent[y] = x;
    else parent[x] = y;
}

bool isSame(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return true;
    else return false;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    for(int i = 0; i <= n; i++) {
        parent.push_back(i);
    }

    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;

        power[temp] = true;
    }

    for(int i = 0; i < m; i++) {
        int p, q, d;
        cin >> p >> q >> d;
        
        v.push_back({p, q, d});
    }

    sort(v.begin(), v.end(), compare);

    int v_size = v.size();

    for(int i = 0; i < v_size; i++) {
        if((power[parent[Find(v[i].a)]] == false || power[parent[Find(v[i].b)]] == false) && isSame(v[i].a, v[i].b) == false) {
            Union(v[i].a, v[i].b);
            result += v[i].cost;
        }
    }

    cout << result;
}
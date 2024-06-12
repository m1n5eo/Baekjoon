#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 200001

struct type {
    int node1, node2, dist;
};

int t, n, m, a, b, d, parent[MAX];

bool compare(type a, type b) {
    return a.dist < b.dist;
}

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

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    while(true) {
        int total = 0, result = 0;
        vector<type> v;

        cin >> n >> m;

        if(n == 0 && m == 0) break;

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < m; i++) {
            cin >> a >> b >> d;

            v.push_back({a, b, d});
            total += d;
        }

        sort(v.begin(), v.end(), compare);

        int v_size = v.size();

        for(int i = 0; i < v_size; i++) {
            if(isSame(v[i].node1, v[i].node2) == false) {
                Union(v[i].node1, v[i].node2);
                result += v[i].dist;
            }
        }

        cout << total-result << "\n";
    }
}
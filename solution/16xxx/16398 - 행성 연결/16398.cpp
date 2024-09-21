#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1001
#define lli long long int

struct type {
    int node1, node2;
    lli dist;
};

int n, parent[MAX];
lli result, map[MAX][MAX];
vector<type> v;

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

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(i < j) {
                v.push_back({i, j, map[i][j]});
            }
        }
        parent[i] = i;
    }

    sort(v.begin(), v.end(), compare);

    int v_size = v.size();

    for(int i = 0; i < v_size; i++) {
        if(isSame(v[i].node1, v[i].node2) == false) {
            Union(v[i].node1, v[i].node2);
            result += v[i].dist;
        }
    }

    cout << result;
}
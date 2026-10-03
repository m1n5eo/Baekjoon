#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55

struct type {
    int x, y, dist;
};

vector<int> parent(MAX, 0);

int Find(int a) {
    if(a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

bool Same(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

bool compare(type a, type b) {
    return a.dist < b.dist;
}

int main() {
    FASTIO

    while(true) {
        int n, k;
        vector<type> v;

        cin >> n;

        if(n == 0) break;

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        cin >> k;

        for(int i = 0; i < k; i++) {
            int _x, _y, _dist;

            cin >> _x >> _y >> _dist;

            v.push_back({_x, _y, _dist});
        }

        sort(v.begin(), v.end(), compare);

        int vSize = v.size(), result = 0;

        for(int i = 0; i < vSize; i++) {
            if(Same(v[i].x, v[i].y) == false) {
                Union(v[i].x, v[i].y);
                result += v[i].dist;
            }
        }

        cout << result << "\n";

        parent.clear();
    }
}
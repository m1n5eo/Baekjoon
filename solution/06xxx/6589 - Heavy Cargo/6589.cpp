#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    int p, q, dist;
};

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

bool compare(type x, type y) {
    return x.dist > y.dist;
}

int main() {
    FASTIO

    int tc = 1;

    while(true) {
        int n, m, cnt = 0, c, result;
        string a, b;
        vector<type> mst;
        map<string, int> city;

        cin >> n >> m;

        if(n == 0 && m == 0) {
            break;
        }

        for(int i = 0; i < n; i++) {
            parent.push_back(i);
        }

        for(int _ = 0; _ < m; _++) {
            cin >> a >> b >> c;

            if(city.find(a) == city.end()) {
                city.insert({a, cnt});
                cnt += 1;
            }
            if(city.find(b) == city.end()) {
                city.insert({b, cnt});
                cnt += 1;
            }

            mst.push_back({city[a], city[b], c});
        }

        sort(mst.begin(), mst.end(), compare);

        cin >> a >> b;

        for(int i = 0; i < m; i++) {
            if(Same(mst[i].p, mst[i].q) == false) {
                Union(mst[i].p, mst[i].q);
                result = mst[i].dist;

                if(Same(city[a], city[b]) == true) {
                    break;
                }
            }
        }

        cout << "Scenario #" << tc << "\n";
        cout << result << " tons" << "\n";
        cout << "\n";
        
        parent.clear();
        mst.clear();
        tc += 1;
    }
}
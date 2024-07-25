#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

struct type {
    int u, v, dist;
};

int n, m, k;
vector<int> parent(MAX, 0);
vector<type> mst;
vector<bool> visit;

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

int main() {
    FASTIO

    visit.push_back(false);

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        int _u, _v;

        cin >> _u >> _v;

        mst.push_back({_u, _v, i+1});
        visit.push_back(false);
    }

    int mstSize = mst.size();

    for(int _ = 0; _ < k; _++) {
        int result = 0, cnt = 0;
        bool check = false;

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < mstSize; i++) {
            if(visit[i] == false && Same(mst[i].u, mst[i].v) == false) {
                Union(mst[i].u, mst[i].v);
                result += mst[i].dist;

                if(check == false) {
                    visit[i] = true;
                    check = true;
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if(Find(i) == 1) cnt += 1;
        }

        if(cnt == n) cout << result << " ";
        else cout << 0 << " ";
    }

    return 0;
}
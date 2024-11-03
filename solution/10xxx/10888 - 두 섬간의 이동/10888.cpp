#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 111111

int n, build;
vector<int> parent, cnt;
vector<lli> f(1, 0), s(1, 0);
pair<lli, lli> result = {0, 0};

int Find(int x) {
    if(x != parent[x]) parent[x] = Find(parent[x]);
    return parent[x];
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

    return x == y? true : false;
}

int main() {
    FASTIO

    cin >> n;

    for(lli i = 1; i < MAX; i++) {
        f.push_back((i/2) * ((i+1)/2*2-1));
        s.push_back(s.back() + f.back());
    }

    for(int i = 0; i <= n; i++) {
        parent.push_back(i);
        cnt.push_back(1);
    }

    for(int _ = 0; _ < n-1; _++) {
        cin >> build;
        
        result.first -= f[cnt[Find(build)]] + f[cnt[Find(build+1)]];
        result.second -= s[cnt[Find(build)]] + s[cnt[Find(build+1)]];

        cnt[Find(build)] = cnt[Find(build)] + cnt[Find(build+1)];
        Union(Find(build), Find(build+1));

        result.first += f[cnt[Find(build)]];
        result.second += s[cnt[Find(build)]];

        cout << result.first << " " << result.second << "\n";
    }
}
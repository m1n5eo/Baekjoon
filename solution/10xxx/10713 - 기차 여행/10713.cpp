#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli solve() {
    int n, m;
    cin >> n >> m;
    vector<int> go;
    vector<lli> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    for(int _ = 0; _ < m; _++) {
        int temp; cin >> temp;
        go.push_back(temp);
    }
    for(int i = 1; i < n; i++) {
        lli temp1, temp2, temp3; cin >> temp1 >> temp2 >> temp3;
        a[i] = temp1; b[i] = temp2; c[i] = temp3;
    }

    vector<lli> imos(n+1, 0);
    for(int i = 0; i < m-1; i++) {
        imos[min(go[i], go[i+1])] += 1;
        imos[max(go[i], go[i+1])] -= 1;
    }

    lli ret = 0, prefix = 0;
    for(int i = 1; i < n; i++) {
        prefix += imos[i];
        ret += min(a[i]*prefix, b[i]*prefix + c[i]);
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
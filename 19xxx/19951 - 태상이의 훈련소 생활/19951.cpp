#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<int> solve() {
    int n, m;
    cin >> n >> m;
    vector<int> init, imos(n+1, 0);
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        init.push_back(temp);
    }
    for(int _ = 0; _ < m; _++) {
        int a, b, k; cin >> a >> b >> k;
        a -= 1; b -= 1;
        imos[a] += k;
        imos[b+1] -= k;
    }

    int prefix = 0;
    for(int i = 0; i < n; i++) {
        prefix += imos[i];
        init[i] += prefix;
    }
    return init;
}

int main() {
    FASTIO
    vector<int> sol = solve();
    for(int s : sol) cout << s << " ";
}
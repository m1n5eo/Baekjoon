#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1000000

vector<int> solve() {
    int n, q;
    cin >> n;
    vector<int> imos(MAX+2, 0);
    for(int _ = 0; _ < n; _++) {
        int s, e; cin >> s >> e;
        imos[s] += 1;
        imos[e+1] -= 1;
    }

    int prefix = 0;
    vector<int> nope(MAX+2, 0);
    for(int i = 0; i <= MAX; i++) {
        prefix += imos[i];
        nope[i] = prefix;
    }

    vector<int> ret;
    cin >> q;
    for(int _ = 0; _ < q; _++) {
        int temp; cin >> temp;
        ret.push_back(nope[temp]);
    }
    return ret;
}

int main() {
    FASTIO
    vector<int> sol = solve();
    for(int s : sol) cout << s << "\n";
}
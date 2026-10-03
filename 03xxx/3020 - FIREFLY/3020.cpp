#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

pair<int, int> solve() {
    int n, h;
    cin >> n >> h;
    vector<int> imos(h+1, 0);
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if(i%2 == 0) {
            imos[h-temp] += 1;
            imos[h] -= 1;
        }
        else if(i%2 == 1) {
            imos[0] += 1;
            imos[temp] -= 1;
        }
    }

    pair<int, int> ret = {imos[0], 1};
    int prefix = imos[0];
    for(int i = 1; i < h; i++) {
        prefix += imos[i];
        if(prefix == ret.first) ret.second += 1;
        else if(prefix < ret.first) ret = {prefix, 1};
    }
    return ret;
}

int main() {
    FASTIO
    pair<int, int> sol = solve();
    cout << sol.first << " " << sol.second << "\n";
}
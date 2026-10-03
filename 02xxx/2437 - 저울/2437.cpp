#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int n;
    cin >> n;
    vector<int> chu;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        chu.push_back(temp);
    }

    sort(chu.begin(), chu.end());
    int ret = chu[0];
    if(ret != 1) return 1;
    for(int i = 1; i < n; i++) {
        if(ret+1 < chu[i]) break;
        else ret += chu[i];
    }
    return ret+1;
}

int main() {
    FASTIO
    cout << solve();
}
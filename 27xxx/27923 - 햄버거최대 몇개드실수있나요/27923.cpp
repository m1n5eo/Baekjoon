#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 444444

lli solve() {
    lli n, k, l;
    cin >> n >> k >> l;
    vector<lli> mass, imos(MAX, 0);
    for(lli i = 0; i < n; i++) {
        lli temp; cin >> temp;
        mass.push_back(temp);
    }
    for(lli _ = 0; _ < k; _++) {
        lli temp; cin >> temp;
        imos[temp] += 1;
        imos[temp+l] -= 1;
    }

    deque<lli> prefix;
    prefix.push_back(0);
    for(lli i = 1; i <= n; i++) prefix.push_back(prefix.back() + imos[i]);
    prefix.pop_front();

    lli ret = 0;
    sort(prefix.begin(), prefix.end());
    sort(mass.begin(), mass.end());
    for(lli i = 0; i < n; i++) ret += mass[i]/pow(2, prefix[i]);
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
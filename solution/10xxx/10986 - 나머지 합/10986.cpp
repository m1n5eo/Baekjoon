#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int main() {
    FASTIO

    int n, m, temp, before = 0;
    lli result = 0;
    
    cin >> n >> m;
    
    vector<int> cnt(m+1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> temp;

        cnt[(before + temp) % m] += 1;
        before = (before + temp) % m;
    }

    cnt[0] += 1;

    for(int i = 0; i < m; i++) {
        result += (lli)cnt[i]*(lli)(cnt[i]-1)/2;
    }

    cout << result;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO
    
    int n, m;
    vector<int> v, prefixSum;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;

        cin >> temp;

        v.push_back(temp);

        if(i != 0) prefixSum.push_back(temp + prefixSum.back());
        else prefixSum.push_back(temp);
    }

    cin >> m;

    for(int _ = 0; _ < m; _++) {
        int a, b;

        cin >> a >> b;

        if(a-2 == -1) cout << prefixSum[b-1] << "\n";
        else cout << prefixSum[b-1]-prefixSum[a-2] << "\n";
    }
}
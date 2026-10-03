#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int n, temp, cnt = 1;
    cin >> n;
    vector<int> vec(n, 0);
    for(int i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    int ret = (n == 1? 1 : 2);
    for(int i = 0; i < n; i++) {
        int left = i, right = n-1;
        while(left+1 < right) {
            if(vec[left] + vec[left+1] <= vec[right]) right -= 1;
            else {
                ret = max(ret, right-left+1);
                break;
            }
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
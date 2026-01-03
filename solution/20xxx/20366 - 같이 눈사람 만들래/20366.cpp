#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

int solve() {
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++) cin >> height[i];

    int ret = INF;
    sort(height.begin(), height.end());
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int left = 0, right = n-1;
            while(left == i || left == j) left += 1;
            while(right == i || right == j) right -= 1;

            int init = height[i] + height[j];
            while(left < right) {
                int now = height[left] + height[right];
                if(init == now) return 0;
                else if(init > now) {
                    left += 1;
                    while(left == i || left == j) left += 1;
                }
                else if(init < now) {
                    right -= 1;
                    while(right == i || right == j) right -= 1;
                }
                ret = min(ret, abs(init-now));
            }
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
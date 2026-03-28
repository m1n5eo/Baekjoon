#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

int solution() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    
    int left = 0, right = n-1, diff = INF;
    while(left < right) {
        diff = min(diff, abs(vec[left] + vec[right] - k));
        if(vec[left] + vec[right] == k) break;
        else if(vec[left] + vec[right] < k) left += 1;
        else if(vec[left] + vec[right] > k) right -= 1;
    }
    
    int target = k-diff, result = 0; left = 0, right = n-1;
    while(left < right) {
        if(vec[left] + vec[right] == target) {
            left += 1;
            right -= 1;
            result += 1;
        }
        else if(vec[left] + vec[right] < k) left += 1;
        else if(vec[left] + vec[right] > k) right -= 1;
    }

    target = k+diff, left = 0, right = n-1;
    while(left < right) {
        if(vec[left] + vec[right] == target) {
            left += 1;
            right -= 1;
            result += 1;
        }
        else if(vec[left] + vec[right] < k) left += 1;
        else if(vec[left] + vec[right] > k) right -= 1;
    }

    return diff != 0? result : result/2;
}

int main() {
    FASTIO
    int tc; cin >> tc;
    while(tc--) cout << solution() << "\n";
}
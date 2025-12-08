#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int n;
    cin >> n;
    vector<int> good;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        good.push_back(temp);
    }

    set<int> ret;
    sort(good.begin(), good.end());
    for(int i = 0; i < n; i++) {
        int left = (i != 0? 0 : 1), right = (i != n-1? n-1 : n-2);
        while(left < right) {
            if(good[left] + good[right] < good[i]) {
                left += 1;
                if(left == i) left += 1;
            }
            else if(good[left] + good[right] > good[i]) {
                right -= 1;
                if(right == i) right -= 1;
            }
            else {
                ret.insert(i);
                break;
            }
        }
    }
    return ret.size();
}

int main() {
    FASTIO
    cout << solve();
}
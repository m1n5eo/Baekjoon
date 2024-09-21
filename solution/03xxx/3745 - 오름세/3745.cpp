#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n;

int main() {
    FASTIO

    while(cin >> n) {
        int result = 0;
        vector<int> arr, v, LIS;

        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;

            arr.push_back(temp);
        }

        for(int i = 0; i < n; i++) {
            if(i == 0 || v.back() < arr[i]) {
                v.push_back(arr[i]);
                LIS.push_back(v.size());
                result = max(result, LIS[i]);
            }
            else {
                int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
                v[idx] = arr[i];
                LIS.push_back(idx+1);
                result = max(result, LIS[i]);
            }
        }

        cout << result << "\n";
    }
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int t;
    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        int n, k;
        vector<int> arr, v;

        cin >> n >> k;

        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;

            arr.push_back(temp);
        }

        for(int i = 0; i < n; i++) {
            if(i == 0 || v.back() < arr[i]) v.push_back(arr[i]);
            else v[lower_bound(v.begin(), v.end(), arr[i]) - v.begin()] = arr[i];
        }

        cout << "Case #" << testcase+1 << "\n";

        if(v.size() < k) cout << 0 << "\n";
        else cout << 1 << "\n";
    }
}
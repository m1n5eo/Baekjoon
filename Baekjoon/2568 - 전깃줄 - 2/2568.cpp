#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n;
vector<pair<int, int>> arr;
vector<int> v, dp;
stack<int> st;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end(), compare);

    for(int i = 0; i < n; i++) {
        if(i == 0 || v.back() < arr[i].second) {
            v.push_back(arr[i].second);
            dp.push_back(v.size());
        }
        else {
            int idx = lower_bound(v.begin(), v.end(), arr[i].second) - v.begin();
            v[idx] = arr[i].second;
            dp.push_back(idx+1);
        }
    }

    int key = v.size();

    for(int i = n-1; i >= 0; i--) {
        if(key == dp[i]) {
            key -= 1;
            continue;
        }
        else {
            st.push(arr[i].first);
        }
    }

    cout << n-v.size() << "\n";

    while(st.size()) {
        cout << st.top() << " ";
        st.pop();
    }
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int solve() {
    int n;
    cin >> n;
    vector<int> vec;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        vec.push_back(temp);
    }

    vector<pair<int, int>> diff;
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            diff.push_back({vec[j]-vec[i], vec[j]});
        }
    }

    vector<pair<int, int>> difference;
    int m = diff.size(), k = diff[0].first, val = diff[0].second;
    for(pair<int, int> d : diff) {
        if(k == d.first) val = max(val, d.second);
        else {
            difference.push_back({k, val});
            k = d.first, val = d.second;
        }
    }

    m = difference.size(); int ret = vec[0];
    sort(difference.begin(), difference.end(), compare);
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int left = 0, right = m-1, key = vec[i]+vec[j];
            while(left <= right) {
                int mid = (left+right)/2;
                if(difference[left].first == key) ret = max(ret, difference[left].second);
                if(difference[right].first == key) ret = max(ret, difference[right].second);
                if(difference[mid].first == key) ret = max(ret, difference[mid].second);

                if(difference[mid].first < key) left = mid+1;
                else right = mid-1;
            }
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
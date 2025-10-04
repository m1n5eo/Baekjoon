#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    int area, height, weight, index;
};

bool compare(type a, type b) {
    if(a.area != b.area) return a.area < b.area;
    else return a.weight < b.weight;
}

vector<int> solve() {
    int n;
    cin >> n;
    vector<type> block(n);
    for(int i = 0; i < n; i++) {
        cin >> block[i].area >> block[i].height >> block[i].weight;
        block[i].index = i+1;
    }
    sort(block.begin(), block.end(), compare);

    // cout << "\n" << "block" << "\n";
    // for(type b : block) cout << b.index << " : " << b.area << " " << b.height << " " << b.weight << "\n";
    // cout << "\n";

    vector<pair<int, vector<int>>> dp(n);
    dp[0] = {block[0].height, {block[0].index}};
    int m = dp[0].first, idx = 0;
    for(int i = 1; i < n; i++) {
        dp[i] = {block[i].height, {block[i].index}};
        for(int j = 0; j < i; j++) {
            if(block[i].weight >= block[j].weight) {
                if(block[i].height + dp[j].first > dp[i].first) {
                    dp[i].first = block[i].height + dp[j].first;
                    dp[i].second.clear();
                    dp[i].second.push_back(block[i].index);
                    for(int d : dp[j].second) dp[i].second.push_back(d);
                }
            }
        }
        if(dp[i].first > m) {
            m = dp[i].first;
            idx = i;
        }
    }

    // cout << "\n" << "dp" << "\n";
    // for(int i = 0; i < n; i++) {
    //     cout << dp[i].first << " / ";
    //     for(int j = 0; j < dp[i].second.size(); j++) cout << dp[i].second[j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    vector<int> ret;
    int ds = dp[idx].second.size();
    for(int i = 0; i < ds; i++) ret.push_back(dp[idx].second[ds-i-1]);
    return ret;
}

int main() {
    FASTIO
    vector<int> sol = solve();
    cout << sol.size() << "\n";
    for(int s : sol) cout << s << "\n";
}
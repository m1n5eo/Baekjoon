#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

int solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> treasure(k, {0, 0});
    for(int i = 0; i < k; i++) cin >> treasure[i].first >> treasure[i].second;
    sort(treasure.begin(), treasure.end(), compare);

    // cout << "\n" << "treasure" << "\n";
    // for(int i = 0; i < k; i++) cout << treasure[i].first << " " << treasure[i].second << "\n";
    // cout << "\n";

    vector<pair<int, int>> com;
    com.push_back(treasure[0]);
    for(int i = 1; i < k; i++) {
        int com_size = com.size();
        for(int j = 0; j < com_size; j++) {
            if(com[j].first <= treasure[i].first && com[j].second <= treasure[i].second) {
                com[j] = treasure[i];
                break;
            }
            else if(j == com_size-1) com.push_back(treasure[i]);
        }
    }
    return com.size();
}

int main() {
    FASTIO
    cout << solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, k, temp, result = 0;
    vector<int> cost, gap;

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        cost.push_back(temp);
    }

    sort(cost.begin(), cost.end());

    for(int i = 0; i < n-1; i++) {
        gap.push_back(cost[i+1]-cost[i]);
    }
    
    sort(gap.begin(), gap.end());

    for(int i = 0; i < n-k; i++) {
        result += gap[i];
    }

    cout << result;
}
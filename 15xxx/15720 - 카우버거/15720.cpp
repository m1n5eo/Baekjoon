#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, m, k, len;
vector<int> burger, side, beverage, result;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    FASTIO

    cin >> n >> m >> k;

    int min_nmk = min(min(n, m), k);
    int max_nmk = max(max(n, m), k);

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        burger.push_back(temp);
    }

    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;

        side.push_back(temp);
    }

    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;

        beverage.push_back(temp);
    }

    sort(burger.begin(), burger.end(), compare);
    sort(side.begin(), side.end(), compare);
    sort(beverage.begin(), beverage.end(), compare);

    int total = 0, sum = 0;

    for(int i = 0; i < max_nmk; i++) {
        int temp = 0;

        if(i < n) temp += burger[i];
        if(i < m) temp += side[i];
        if(i < k) temp += beverage[i];

        result.push_back(temp);
        total += temp;
    }

    for(int i = 0; i < max_nmk; i++) {
        if(i < min_nmk) sum += result[i]*0.9;
        else sum += result[i];
    }

    cout << total << "\n" << sum;
}
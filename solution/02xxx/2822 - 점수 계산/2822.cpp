#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>

int sum;
vector<pii> v;

bool compare1(pii a, pii b) {
    return a.first < b.first;
}

bool compare2(pii a, pii b) {
    return a.second < b.second;
}

int main() {
    FASTIO

    for(int i = 0; i < 8; i++) {
        int num;

        cin >> num;

        v.push_back({num, i+1});
    }

    sort(v.begin(), v.end(), compare1);

    for(int i = 0; i < 3; i++) v.erase(v.begin());

    sort(v.begin(), v.end(), compare2);

    for(int i = 0; i < 5; i++) sum += v[i].first;

    cout << sum << "\n";
    for(int i = 0; i < 5; i++) cout << v[i].second << " ";
}
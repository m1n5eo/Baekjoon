#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111
#define lli long long int

int n;
vector<pair<int, int>> v;

bool compare(pair<int,int> a, pair<int, int> b) {
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        int number;
        cin >> number;

        v.push_back({number, 0});
    }

    for(int i = 0; i < n; i++) {
        int cost;
        cin >> cost;

        v[i].second = cost;
    }

    sort(v.begin(), v.end(), compare);

    lli result = 0;

    for(int i = 0; i < n-1; i++) {
        if(v[i].first == v[i+1].first) {
            result += (lli)v[i].second;
        }
    }

    cout << result;
}
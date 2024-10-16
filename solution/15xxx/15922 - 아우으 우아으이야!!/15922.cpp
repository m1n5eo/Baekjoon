#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define INF 1000000000

int main() {
    FASTIO

    int n, a, b, result = 0;
    vector<pii> point;
    pii now = {-INF, -INF};

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        cin >> a >> b;
        point.push_back({a, b});
    }

    for(int i = 0; i < n; i++) {
        if(now.second < point[i].first) {
            result += now.second-now.first;
            now = {point[i].first, point[i].second};
        }
        else {
            now.second = max(now.second, point[i].second);
        }
    }

    result += now.second-now.first;

    cout << result;
}
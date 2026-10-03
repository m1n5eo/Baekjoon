#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n;
vector<pair<long double, long double>> v;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        long double a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    long double res = 0;
    for(int i = 1; i < n-1; i++) {
        long double temp = (v[i].first-v[0].first)*(v[i+1].second-v[0].second)-(v[i].second-v[0].second)*(v[i+1].first-v[0].first);
        res += temp/2.0;
    }

    if(res < 0) res *= (-1);

    cout << fixed;
    cout.precision(1);
    cout << res;

    return 0;
}
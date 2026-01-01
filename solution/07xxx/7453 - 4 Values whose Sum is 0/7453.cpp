#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

bool compare(lli a, lli b) {
    return a < b;
}

lli solve() {
    lli n;
    cin >> n;
    vector<lli> a(n), b(n), c(n), d(n);
    for(lli i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<lli> x, y;
    for(lli i = 0; i < n; i++) {
        for(lli j = 0; j < n; j++) {
            x.push_back(a[i]+b[j]);
            y.push_back(c[i]+d[j]);
        }
    }
    sort(x.begin(), x.end(), compare);
    sort(y.begin(), y.end(), compare);

    vector<pair<lli, lli>> xx;
    lli k = x[0], cnt = 1;
    for(lli i = 1; i < n*n; i++) {
        if(k == x[i]) cnt += 1;
        else {
            xx.push_back({k, cnt});
            k = x[i], cnt = 1;
        }
    }
    xx.push_back({k, cnt});

    n = xx.size(); lli m = y.size(), ret = 0;
    for(lli i = 0; i < m; i++) {
        lli left = 0, right = n-1, key = -y[i];
        while(left <= right) {
            lli mid = (left+right)/2;
            if(xx[left].first == key) {
                ret += xx[left].second;
                break;
            }
            else if(xx[right].first == key) {
                ret += xx[right].second;
                break;
            }
            else if(xx[mid].first == key) {
                ret += xx[mid].second;
                break;
            }
            if(xx[mid].first < key) left = mid+1;
            else right = mid-1;
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
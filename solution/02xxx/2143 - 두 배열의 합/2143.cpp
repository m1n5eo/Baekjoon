#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define endl "\n"

lli solve() {
    lli t, n, m;
    vector<lli> a, b;
    deque<lli> pa = {0}, pb = {0};
    cin >> t;
    cin >> n;
    for(lli i = 0; i < n; i++) {
        lli temp; cin >> temp;
        a.push_back(temp);
        pa.push_back(pa.back() + temp);
    }
    cin >> m;
    for(lli i = 0; i < m; i++) {
        lli temp; cin >> temp;
        b.push_back(temp);
        pb.push_back(pb.back() + temp);
    }

    map<lli, lli> mb;
    for(lli i = 0; i < m+1; i++) {
        for(lli j = i+1; j < m+1; j++) {
            lli k = pb[j] - pb[i];
            if(mb.find(k) == mb.end()) mb[k] = 1;
            else mb[k] += 1;
        }
    }

    vector<pair<lli, lli>> vb;
    for(pair<lli, lli> tmp : mb) vb.push_back(tmp);

    lli ret = 0;
    n = pa.size(); m = vb.size();
    for(lli i = 0; i < n; i++) {
        for(lli j = i+1; j < n; j++) {
            lli k = t-(pa[j]-pa[i]);
            lli left = 0, right = m-1;
            while(left <= right) {
                lli mid = (left+right)/2;
                if(vb[left].first == k) {
                    ret += vb[left].second;
                    break;
                }
                else if(vb[mid].first == k) {
                    ret += vb[mid].second;
                    break;
                }
                else if(vb[right].first == k) {
                    ret += vb[right].second;
                    break;
                }
                else if(vb[mid].first < k) left = mid+1;
                else if(vb[mid].first > k) right = mid-1;
            }
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
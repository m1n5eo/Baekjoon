#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli solve() {
    lli n;
    cin >> n;
    vector<lli> coding;
    for(lli i = 0; i < n; i++) {
        lli temp; cin >> temp;
        coding.push_back(temp);
    }

    lli ret = 0;
    sort(coding.begin(), coding.end());
    for(lli i = 0; i < n; i++) {
        for(lli j = i+1; j < n; j++) {
            lli k = -(coding[i]+coding[j]);
            lli a = lower_bound(coding.begin()+j+1, coding.end(), k) - coding.begin();
            lli b = upper_bound(coding.begin()+j+1, coding.end(), k) - coding.begin();
            ret += b-a;
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
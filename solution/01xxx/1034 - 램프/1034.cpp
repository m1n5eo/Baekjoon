#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int n, m, k;
    cin >> n >> m;
    map<string, int> status;
    for(int i = 0; i < n; i++) {
        string temp; cin >> temp;
        if(status.find(temp) != status.end()) status[temp] += 1;
        else status[temp] = 1;
    }
    cin >> k;

    int ret = 0;
    for(pair<string, int> s : status) {
        int cnt = 0;
        for(char sf : s.first) {
            if(sf == '0') cnt += 1;
        }
        if(k >= cnt && k%2 == cnt%2) ret = max(ret, s.second);
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}
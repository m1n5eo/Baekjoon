#include <bits/stdc++.h>
using namespace std;

string str[33], temp;
int t, n, k, cnt[33];
long long int dap;

int main() {
    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> temp >> str[i];
        sort(str, str+n);
        string checkStr = str[0];
        int dap = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(checkStr != str[i]) {
                dap += dap * cnt + cnt;
                cnt = 0;
                checkStr = str[i];
            }
            if(checkStr == str[i]) cnt++;
        }
        dap += dap * cnt + cnt;
        printf("%lld\n", dap);
    }
}
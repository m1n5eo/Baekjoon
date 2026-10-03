#include <bits/stdc++.h>
using namespace std;

int temp, sum, maxnum = -1234567890, maxidx, cnt[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 10; i++) {
        cin >> temp;
        sum += temp;
        cnt[temp]++;
    }
    for(int i = 0; i < 1000; i++) {
        if(maxnum < cnt[i]) {
            maxnum = cnt[i];
            maxidx = i;
        }
    }
    cout << sum/10 << "\n" << maxidx;
}
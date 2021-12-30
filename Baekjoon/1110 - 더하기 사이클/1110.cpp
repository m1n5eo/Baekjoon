#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 1;
    cin >> n;
    int m = n;
    while(1) {
        m = (m%10)*10 + (m/10 + m%10)%10;
        if(n == m) break;
        else cnt += 1;
    }
    cout << cnt;
}
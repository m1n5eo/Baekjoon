#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, t;
    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n >> m;
        int k = m-n;
        for(long long int i = 1; i <= 100000; i++) {
            if(i*i >= k) {
                if(i*i-i < k) cout << i*2-1 << "\n";
                else cout << i*2-2 << "\n";
                break;
            }
        }
    }
}

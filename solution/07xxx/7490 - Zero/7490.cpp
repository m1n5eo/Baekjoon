#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void cal(int n, int idx, int buho, int now, int sum, string print) {
    if(idx == n) {
        if(buho == 0 && sum+now == 0) cout << print << "\n";
        else if(buho == 1 && sum-now == 0) cout << print << "\n";
        return;
    }

    cal(n, idx+1, buho, now*10+(idx+1), sum, print+' '+to_string(idx+1));
    cal(n, idx+1, 0, idx+1, (buho? sum-now : sum+now), print+'+'+to_string(idx+1));
    cal(n, idx+1, 1, idx+1, (buho? sum-now : sum+now), print+'-'+to_string(idx+1));
}

int main() {
    FASTIO
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        cal(n, 1, 0, 1, 0, "1");
        cout << "\n";
    }
}
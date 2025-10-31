#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int n;
    cin >> n;
    vector<int> red(n+1, 0), blue(n+1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            int color; cin >> color;
            if(color == 0) {
                red[i] += 1;
                red[j] += 1;
            }
            else {
                blue[i] += 1;
                blue[j] += 1;
            }
        }
    }
    
    int ret = 0;
    for(int i = 1; i <= n; i++) ret += red[i]*blue[i];
    return n*(n-1)*(n-2)/6 - ret/2;
}

int main() {
    FASTIO
    int testcase; cin >> testcase;
    for(int tc = 0; tc < testcase; tc++) cout << solve() << "\n";
}
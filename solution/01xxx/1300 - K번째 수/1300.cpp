#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli n, k;

lli Find(lli start, lli end) {
    lli mid = (start + end) / 2;
    lli count = 0;

    if(start > end) {
        return start;
    }
    
    for(int i = 1; i <= n; i++) {
        count += min(mid / i, n);
    }

    if(count >= k) return Find(start, mid - 1);
    else return Find(mid + 1, end);
}

int main() {
    FASTIO

    cin >> n;
    cin >> k;

    cout << Find(1, n*n);
}
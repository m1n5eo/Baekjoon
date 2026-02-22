#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli Find(lli x) {
    lli ret = (x+1)/2;
    for(lli k = 2; x/k; k*=2) {
        lli p = x/k;
        ret += (p%2? (p/2)*k + (x%k+1) : (p/2)*k);
    }
    return ret;
}

lli solution() {
    lli n, m;
    cin >> n >> m;
    return Find(m) - Find(n-1);
}

int main() {
    FASTIO
    cout << solution();
}
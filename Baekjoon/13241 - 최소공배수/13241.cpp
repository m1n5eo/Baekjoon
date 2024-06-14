#include <iostream>
#include <numeric>
using namespace std;

#define lli long long int

lli n, m;

lli gcd(lli a, lli b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cout << n*m/gcd(n, m);
}
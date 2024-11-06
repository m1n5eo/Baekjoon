#include <iostream>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MOD 1000000007

lli n;
map<lli, lli> m;

lli fibo(lli x) {
    if(m[x]) return m[x];
    return m[x] = x%2 == 0? (fibo(x/2)*(fibo(x/2+1)+fibo(x/2-1)))%MOD : (fibo((x+1)/2)*fibo((x+1)/2)+fibo((x-1)/2)*fibo((x-1)/2))%MOD;
}

int main() {
    FASTIO

    cin >> n;

    m.insert({0, 0});
    m.insert({1, 1});
    m.insert({2, 1});

    cout << fibo(n%2 == 0? n : n+1);
}
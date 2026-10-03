#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MOD 1000000007

int n, a = 1, b = 2, c = 3;

int main() {
    FASTIO

    cin >> n;
    
    for(int i = 5; i <= n; i++) {
        a = b;
        b = c;
        c = (a+b)%MOD;
    }

    cout << c << " " << n-2;
}
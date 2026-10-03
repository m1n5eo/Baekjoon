#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int main() {
    FASTIO
    
    lli n, result;

    cin >> n;

    result = n;

    for(lli i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            result = result/i*(i-1);
            while(n%i == 0) n /= i;
        }
    }

    if(n > 1) result = result/n*(n-1);

    cout << result;
}
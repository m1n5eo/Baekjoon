#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 1111111111

int main() {
    FASTIO

    lli n;

    cin >> n;

    vector<lli> divisor;

    for(lli i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            divisor.push_back(i);
            divisor.push_back(n/i);
        }
    }

    sort(divisor.begin(), divisor.end());

    for(lli k : divisor) {
        lli num = k, phi = k;

        for(lli i = 2; i*i <= num; i++) {
            if(num%i == 0) {
                phi = phi/i*(i-1);
                while(num%i == 0) num /= i;
            }
        }

        if(num > 1) phi = phi/num*(num-1);

        if(k*phi == n) {
            cout << k;
            exit(0);
        }
    }

    cout << -1;
}
#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int pow(int k, int now) {
    if(now == 0) return 1;
    else return pow(k, now-1) * k;
}

int main() {
    FASTIO

    int n, a, b;

    cin >> n;
    cin >> a >> b;

    if(n < a+b) {
        a = n-a;
        b = n-b;
    }

    int k = a+b, p = pow(2, n)/2, result = 0;

    for(int i = 0; i < k; i++) {
        result += p;
        p /= 2;
    }

    cout << result;
}
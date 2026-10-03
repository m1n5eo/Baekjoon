#include <iostream>
using namespace std;

int cnt1, cnt2, f[44];

int fib(int n) {
    if(n == 1 || n == 2) {
        cnt1 += 1;
        return 1;
    }
    else return fib(n-1)+fib(n-2);
}

int fibonacci(int n) {
    f[1] = 1; f[2] = 1;
    for(int i = 3; i <= n; i++) {
        cnt2 += 1;
        f[i] = f[i-1]+f[i-2];
    }

    return f[n];
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int temp1 = fib(n);
    int temp2 = fibonacci(n);

    cout << cnt1 << " " << cnt2;
}
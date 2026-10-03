#include <iostream>
using namespace std;

#define pi 3.141592

double d, r;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> d >> r;

    cout.precision(6);
    cout << fixed;
    cout << d*2 + 2*pi*r;

    return 0;
}
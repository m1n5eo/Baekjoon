#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int p, q;

    cin >> p;
    cin >> q;

    if(p <= 50 && q <= 10) cout << "White";
    else if(q > 30) cout << "Red";
    else cout << "Yellow";
}
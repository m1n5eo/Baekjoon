#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli n;

int main() {
    FASTIO

    cin >> n;

    if(n%7 == 0 || n%7 == 2) cout << "CY";
    else cout << "SK";
}
#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli n;

int main() {
    FASTIO

    cin >> n;
    
    if(n%5 == 2 || n%5 == 0) cout << "CY";
    else cout << "SK";
}
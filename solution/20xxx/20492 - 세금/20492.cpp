#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n;

    cin >> n;
    cout << n/100*78 << " " << n/1000*956;
}
#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, m;

int main() {
    FASTIO

    cin >> n >> m;

    if(n > m) swap(n, m);

    cout << n*100/2;
}
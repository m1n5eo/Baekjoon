#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, cnt;

int main() {
    FASTIO

    cin >> n;

    for(int i = 1; i*i <= n; i++) cnt += 1;

    cout << cnt;
}
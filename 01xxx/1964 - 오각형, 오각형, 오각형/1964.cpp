#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MOD 45678

int main() {
    FASTIO

    int n, result = 5;

    cin >> n;

    for(int i = 2; i <= n; i++) result = (result+i*3+1)%MOD;

    cout << result;
}
#include <iostream>
using namespace std;

int n, a, b = 1;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 2; i <= n; i++) {
        int temp1 = b;
        int temp2 = a+b;

        a = temp1;
        b = temp2;
    }

    cout << a << " " << b;
}
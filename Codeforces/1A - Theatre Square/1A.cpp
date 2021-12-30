#include <iostream>
using namespace std;

int main() {
    long long int n, m, a, temp;
    cin >> n >> m >> a;
    cout << ((n-1)/a+1)*((m-1)/a+1);
}
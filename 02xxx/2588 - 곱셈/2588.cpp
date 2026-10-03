#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << n*(m%10) << "\n" << n*((m/10)%10) << "\n" << n*(m/100) << "\n" << n*m;
}

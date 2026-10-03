#include <iostream>
using namespace std;

int n, m, prt[111];
int a, b, c;

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        for(int j = a; j <= b; j++) {
            prt[j] = c;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << prt[i] << " ";
    }
}
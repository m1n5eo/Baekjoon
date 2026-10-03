#include <iostream>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void cantor(int n) {
    if(n == 0) {
        cout << "-";
        return;
    }

    int loop = pow(3, n-1);

    cantor(n-1);
    for(int i = 0; i < loop; i++) cout << " ";
    cantor(n-1);
}

int main() {
    FASTIO
    
    int n;

    while(cin >> n) {
        cantor(n);
        cout << "\n";
    }
}
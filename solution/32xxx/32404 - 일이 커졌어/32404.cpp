#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO
    
    int n;

    cin >> n;

    for(int i = 0; i < n/2; i++) {
        cout << n/2+1+i << " ";
        cout << n/2-i << " ";
    }

    if(n%2 == 1) {
        cout << n << " ";
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, f;
    cin >> n >> f;
    for(int i = 0; i < 100; i++) {
        n = (n/100)*100+i;
        if(n%f == 0) {
            if(i%100 < 10) cout << "0";
            cout << i%100;
            return 0;
        }
    }
}
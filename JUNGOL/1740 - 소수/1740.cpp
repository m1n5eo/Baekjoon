#include <iostream>
using namespace std;

bool prime[11111] = {true, true, };

int main() {
    for(int i = 2; i < 11111; i++) {
        if(prime[i] == false) {
            for(int j = i*2; j < 11111; j+=i) {
                prime[j] = true;
            }
        }
    }

    int n, m;
    cin >> n >> m;

    int sum = 0, small = 1234567890;
    for(int i = n; i <= m; i++) {
        if(prime[i] == false) {
            if(small > i) small = i;
            sum += i;
        }
    }
    if(sum == 0) cout << -1;
    else cout << sum << "\n" << small;
}
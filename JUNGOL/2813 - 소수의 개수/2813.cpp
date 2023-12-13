#include <iostream>
using namespace std;

bool prime[3333333] = {true, true, };

int main() {
    for(int i = 2; i < 3333333; i++) {
        if(prime[i] == false) {
            for(int j = i*2; j < 3333333; j+=i) {
                prime[j] = true;
            }
        }
    }

    int n, m;
    cin >> n >> m;

    int cnt = 0;
    for(int i = n; i <= m; i++) {
        if(prime[i] == false) cnt += 1;
    }
    cout << cnt;
}
#include <iostream>
using namespace std;

bool prime[1111111] = {true, true, }; // 소수면 false

int main() {
    for(int i = 2; i < 1111111; i++) {
        if(prime[i] == false) {
            for(int j = i*2; j < 1111111; j+=i) {
                prime[j] = true;
            }
        }
    }

    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        if(prime[m] == false) {
            cout << m << "\n";
            continue;
        }
        for(int j = 0; ; j++) {

            if(m-j > 0 && prime[m-j] == false && prime[m+j] == false) {
                cout << m-j << " " << m+j << "\n";
                break;
            }
            else if(m-j > 0 && prime[m-j] == false) {
                cout << m-j << "\n";
                break;
            }
            else if(prime[m+j] == false) {
                cout << m+j << "\n";
                break;
            }
        }
    }
}
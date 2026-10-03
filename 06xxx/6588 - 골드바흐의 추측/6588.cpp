#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    cin.tie(0);
    cout.tie(0);
    
    int n;
    bool sosu[1111111] = {true, true, };

    for(int i = 2; i < 1111111; i++) {
        if(sosu[i] == false) {
            for(int j = i*2; j < 1111111; j+=i) {
                sosu[j] = true;
            }
        }
    }

    while(true) {
        cin >> n;
        
        if(n == 0) break;

        for(int i = 2; i <= n/2; i++) {
            if(sosu[i] == false && sosu[n-i] == false) {
                cout << n << " = " << i << " + " << n-i << "\n";
                break;
            }
        }
    }

    return 0;
}
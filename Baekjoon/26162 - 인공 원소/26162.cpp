#include <iostream>
using namespace std;

int t, n;
bool res[222], prime[222] = {true, true, };

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 2; i < 222; i++) {
        if(prime[i] == false) {
            for(int j = i+i; j < 222; j+=i) {
                prime[j] = true;
            }
        }
    }

    for(int i = 1; i < 222; i++) {
        for(int j = 1; j < 222; j++) {
            if(i+j < 222 && prime[i] == false && prime[j] == false) {
                res[i+j] = true;
            }
        }
    }

    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n;

        if(res[n] == false) cout << "No\n";
        else if(res[n] == true) cout << "Yes\n";
    }

    return 0;
}
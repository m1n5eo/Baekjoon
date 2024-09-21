#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111111

int n;
bool prime[MAX];

int main() {
    FASTIO

    for(int i = 2; i*i < MAX; i++) {
        if(prime[i] == false) {
            for(int j = i*2; j < MAX; j+=i) {
                prime[j] = true;
            }
        }
    }

    while(cin >> n) {
        if(n < 8) {
            cout << "Impossible.\n";
            continue;
        }
        
        vector<int> result;

        if(n%2 == 0) {
            result.push_back(2);
            result.push_back(2);
        }
        else {
            result.push_back(2);
            result.push_back(3);
        }

        for(int i = 2; i < n; i++) {
            if(prime[i] == false && prime[n-i-result[0]-result[1]] == false) {
                result.push_back(i);
                result.push_back(n-i-result[0]-result[1]);

                break;
            }
        }

        for(int i = 0; i < 4; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
}
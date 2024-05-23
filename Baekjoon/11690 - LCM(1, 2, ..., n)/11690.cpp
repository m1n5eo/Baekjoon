#include <iostream>
using namespace std;

#define NUM 111111111
#define MOD 4294967296

int n;
unsigned long long int sum = 1, temp;
bool prime[NUM];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 2; i*i < NUM; i++) {
        if(prime[i] == false) {
            for(int j = i*2; j < NUM; j+=i) {
                prime[j] = true;
            }
        }
    }
    
    cin >> n;
    for(int i = 2; i <= n; i++) {
        if(prime[i] == false) {
            unsigned long long int temp = 1;

            while(temp*i <= n) {
                temp = temp*i;
            }

            sum = sum*temp%MOD;
        }
    }

    cout << sum;

    return 0;
}
#include <iostream>
using namespace std;

bool prime[2222222] = {true, true, };

int main() {
    for(int i = 2; i <= 2222222; i++) {
        if(prime[i] == false) {
            for(int j = i*2; j <= 2222222; j+=i) {
                prime[j] = true;
            }
        }
    }
    long long int sum = 0;
    for(int i = 1; i <= 2000000; i++) {
        if(prime[i] == false) sum += i;
    }
    cout << sum;
}
#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000
#define MAX 1500000
#define ulli unsigned long long int

ulli n;
int fibo[MAX+1] = {0, 1, };

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 2; i <= MAX; i++) {
        fibo[i] = (fibo[i-1]+fibo[i-2])%MOD;
    }

    cin >> n;
    cout << fibo[n%MAX];
}
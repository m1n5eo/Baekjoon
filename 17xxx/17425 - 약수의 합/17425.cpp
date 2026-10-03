#include <iostream>
using namespace std;

#define MAX 1111111
#define ulli unsigned long long int

ulli t, n, sum[MAX];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 1; i < MAX; i++) {
        for(int j = i; j < MAX; j+=i) {
            sum[j] += i;
        }
    }

    for(int i = 2; i < MAX; i++) {
        sum[i] = sum[i-1]+sum[i];
    }

    cin >> t;

    for(int _ = 0; _ < t; _++) {
        cin >> n;

        cout << sum[n] << "\n";
    }
}
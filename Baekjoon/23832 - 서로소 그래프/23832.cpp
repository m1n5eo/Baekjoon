#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, sum = 0;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int num = i, result = i;

        for(int j = 2; j*j <= num; j++) {
            if(num%j == 0) {
                result = result/j*(j-1);
                while(num%j == 0) num = num/j;
            }
        }

        if(num > 1) result = result/num*(num-1);

        sum += result;
    }

    cout << sum-1;
}
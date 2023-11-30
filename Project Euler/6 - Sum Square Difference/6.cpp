#include <iostream>
using namespace std;

int main() {
    int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= 100; i++) {
        sum1 = sum1 + i*i;
        sum2 = sum2 + i;
    }
    cout << sum2*sum2 - sum1;
}
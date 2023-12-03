#include <iostream>
using namespace std;

int main() {
    int res = 0;
    for(int i = 2; i <= 10000; i++) {
        int sum1 = 1;
        for(int j = 2; j*j <= i; j++) {
            if(i%j == 0) sum1 += j+(i/j);
        }
        int sum2 = 1;
        for(int j = 2; j*j <= sum1; j++) {
            if(sum1%j == 0) sum2 += j+(sum1/j);
        }
        if(sum1 != 1 && sum2 != 1 && sum1 != sum2 && i == sum2) {
            cout << i << " ";
            res += i;
        }
    }
    cout << "\n" << res;
}
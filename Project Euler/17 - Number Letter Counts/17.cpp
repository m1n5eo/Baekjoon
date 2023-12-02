#include <iostream>
using namespace std;

int cnt[1111] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8, 6, };

int main() {
    cnt[30] = 6; cnt[40] = 5; cnt[50] = 5; cnt[60] = 5; cnt[70] = 7; cnt[80] = 6; cnt[90] = 6; cnt[100] = 10;
    for(int i = 1; i <= 100; i++) {
        if(!cnt[i]) cnt[i] = cnt[i/10*10] + cnt[i%10];
    }
    for(int i = 101; i < 1000; i++) {
        if(!cnt[i]) {
            if(i%100 != 0) cnt[i] = cnt[i/100] + 7 + 3 + cnt[i%100];
            else if(i%100 == 0) cnt[i] = cnt[i/100] + 7;
        }
    }
    cnt[1000] = 11;

    int sum = 0;
    for(int i = 1; i <= 1000; i++) sum += cnt[i];
    cout << sum;
}
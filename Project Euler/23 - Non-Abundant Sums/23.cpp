#include <iostream>
using namespace std;

int arr[33333];
bool abundant[33333];

int main() {
    for(int i = 1; i < 33333; i++) {
        int sum = 0;
        for(int j = 1; j*j <= i; j++) {
            if(i%j == 0 && j*j != i) {
                sum += j+(i/j);
            }
            else if(i%j == 0 && j*j == i) {
                sum += j;
            }
        }
        arr[i] = sum-i;
    }

    for(int i = 1; i < 33333; i++) {
        if(arr[i] <= i) abundant[i] = false;
        else if(arr[i] > i) abundant[i] = true;
    }

    int res = 0;
    for(int i = 2; i < 33333; i++) {
        for(int j = 1; j <= i/2; j++) {
            if(abundant[j] == true && abundant[i-j] == true) break;
            if(j == i/2) res += i;
        }
    }
    cout << res+1;
}
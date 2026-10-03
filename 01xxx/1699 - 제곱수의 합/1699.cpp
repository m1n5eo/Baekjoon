#include <iostream>
using namespace std;

int arr[111111];

int main() {
    for(int i = 1; i <= 100000; i++) arr[i] = 1234567890;
    for(int i = 1; i <= 316; i++) {
        arr[i*i] = 1;
        arr[i*i+1] = 2;
        if(i*i*2 <= 100000) arr[i*i*2] = 2;
    }
    for(int i = 2; i <= 100000; i++) {
        if(arr[i] != 1234567890) continue;
        for(int j = 1; j*j <= i; j++) {
            arr[i] = min(arr[i], arr[j*j]+arr[i-j*j]);
        }
    }

    int n;
    cin >> n;
    cout << arr[n];
}
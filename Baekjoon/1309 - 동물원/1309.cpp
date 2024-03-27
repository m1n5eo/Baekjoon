#include <iostream>
using namespace std;

int arr[111111] = {1, 3};

int main() {
    for(int i = 2; i <= 100000; i++) {
        arr[i] = (arr[i-1]*2 + arr[i-2]) % 9901;
    }

    int n;
    cin >> n;
    cout << arr[n];
}
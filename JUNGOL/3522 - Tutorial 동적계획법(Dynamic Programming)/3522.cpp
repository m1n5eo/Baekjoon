#include <iostream>
using namespace std;

int arr[111111] = {0, 1, 1, };

int fibo(int num) {
    if(arr[num]) return arr[num];
    return (fibo(num-2) + fibo(num-1))%1000000007;
}

int main() {
    for(int i = 2; i < 111111; i++) {
        arr[i] = fibo(i);
    }

    int n;
    cin >> n;
    cout << arr[n];
}
#include <iostream>
using namespace std;

int main() {
    long long int arr[22][22];
    for(int i = 1; i < 22; i++) {
        arr[i][1] = 1;
        arr[1][i] = 1;
    }
    for(int i = 2; i < 22; i++) {
        for(int j = 2; j < 22; j++) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    cout << arr[21][21];
}
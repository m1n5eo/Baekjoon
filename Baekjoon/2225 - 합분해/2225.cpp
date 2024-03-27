#include <iostream>
using namespace std;

int arr[222][222];

int main() {
    for(int i = 1; i <= 200; i++) {
        for(int j = 1; j <= 200; j++) {
            if(i == 1) arr[1][j] = j;
            else if(j == 1) arr[i][1] = 1;
            else arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % 1000000000;
        }
    }
    
    int n, k;
    cin >> n >> k;
    cout << arr[n][k];
}
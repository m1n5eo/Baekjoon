#include <iostream>
using namespace std;

int arr[111][111];

int main() {
    for(int i = 1; i <= 100; i++) arr[1][i] = i-1;
    for(int i = 2; i <= 100; i++) {
        for(int j = i+1; j <= 100; j++) {
            arr[i][j] = arr[i][(j-1)%i+1] + (j-1)/i*i;
            arr[j][i] = arr[(j-1)%i+1][i];
        }
    }

    int n, m;
    cin >> n >> m;
    cout << arr[n][m];
}
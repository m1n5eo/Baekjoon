#include <iostream>
using namespace std;

int main() {
    int arr[22][22], maxGop = 0;
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            int temp[4] = {1, 1, 1, 1};
            for(int k = 0; k <= 3; k++) {
                if(j+k < 20) temp[0] = temp[0] * arr[i][j+k];
                if(i+k < 20) temp[1] = temp[1] * arr[i+k][j];
                if(i+k < 20 && j+k < 20) temp[2] = temp[2] * arr[i+k][j+k];
                if(i-k >= 0 && j+k < 20) temp[3] = temp[3] * arr[i-k][j+k];
            }
            for(int k = 0; k < 4; k++) {
                if(temp[k] > maxGop) maxGop = temp[k];
            }
        }
    }
    cout << maxGop;
}
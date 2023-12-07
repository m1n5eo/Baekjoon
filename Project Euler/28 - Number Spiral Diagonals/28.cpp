#include <iostream>
#include <iomanip>
using namespace std;

#define NUMBER 1001

int arr[NUMBER][NUMBER];

int main() {
    int i = 0, j = 0, cnt = 0, sw = 0;
    while(1) {
        arr[i][j] = (NUMBER*NUMBER) - cnt++;
        if(i == NUMBER/2 && j == NUMBER/2) break;
        if(sw == 0) {
            if(j+1 < NUMBER && arr[i][j+1] == 0) j = j+1;
            else if(j+1 == NUMBER || arr[i][j+1] != 0) {
                i = i+1;
                sw = 1;
            }
        }
        else if(sw == 1) {
            if(i+1 < NUMBER && arr[i+1][j] == 0) i = i+1;
            else if(i+1 == NUMBER || arr[i+1][j] != 0) {
                j = j-1;
                sw = 2;
            }
        }
        else if(sw == 2) {
            if(j-1 > -1 && arr[i][j-1] == 0) j = j-1;
            else if(j-1 == -1 || arr[i][j-1] != 0) {
                i = i-1;
                sw = 3;
            }
        }
        else if(sw == 3) {
            if(i-1 > -1 && arr[i-1][j] == 0) i = i-1;
            else if(i-1 == -1 || arr[i-1][j] != 0) {
                j = j+1;
                sw = 0;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < NUMBER; i++) {
        sum += arr[i][i];
        sum += arr[i][NUMBER-i-1];
    }
    cout << sum - arr[NUMBER/2][NUMBER/2];
}
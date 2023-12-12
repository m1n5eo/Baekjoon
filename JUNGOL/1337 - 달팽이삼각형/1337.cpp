#include <iostream>
using namespace std;

int arr[111][111];

int main() {
    int n;
    cin >> n;

    int i = 0, j = 0, sw = 0, cnt = 0, temp = 1;
    while(true) {
        arr[i][j] = temp;
        if(temp == 10) temp = 1;
        else temp += 1;

        cnt += 1;
        if(n%2 == 0 && cnt == (n/2)*(n+1)) break;
        else if(n%2 == 1 && cnt == n*(n/2+1)) break;

        if(sw == 0) {
            if(i == n-1 || arr[i+1][j+1] != 0) {
                sw = 1;
                j = j-1;
            }
            else {
                i = i+1;
                j = j+1;
            }
        }
        else if(sw == 1) {
            if(j == 0 || arr[i][j-1] != 0) {
                sw = 2;
                i = i-1;
            }
            else j = j-1;
        }
        else if(sw == 2) {
            if(i == 0 || arr[i-1][j] != 0) {
                sw = 0;
                i = i+1;
                j = j+1;
            }
            else i = i-1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << arr[i][j]-1 << " ";
        }
        cout << "\n";
    }
}
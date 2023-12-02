#include <iostream>
#include <string>
using namespace std;

int arr[1111111];

int main() {
    int cnt, idx, cntMax = 0;
    for(int i = 1; i < 1000001; i++) {
        cnt = 0;
        for(long long int j = i; j != 1; j = (j%2 == 0)? j/2:j*3+1) {
            if(j < 1000001 && arr[j] != 0) {
                cnt = cnt+arr[j];
                break;
            }
            else cnt++;
        }
        arr[i] = cnt;
        if(cnt > cntMax) {
            cntMax = cnt;
            idx = i;
        }
    }
    cout << idx << " : " << cntMax+1;
}